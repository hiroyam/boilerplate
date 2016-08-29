#include "./util.hpp"

using namespace cc;

void run() {
    sleep_ms(100);
    std::cout << "hoge\n";

    const int N = 1024;

    vec_t a(N * N);
    vec_t b(N * N);
    vec_t c(N * N);
    vec_t tb(N * N);
    uniform_rand(a.begin(), a.end(), 0.0, 1.0);
    uniform_rand(b.begin(), b.end(), 0.0, 1.0);

    timer t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tb_i = j + i * N;
            int b_i  = i + j * N;
            tb[tb_i] = b[b_i];
        }
    }
    for (int i = 0; i < N; i++) {
        progress_display(i, N);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k += sizeof(__m256) / sizeof(float)) {
                int a_i = k + i * N;
                int b_i = k + j * N;
                int c_i = j + i * N;

                __m256 va, vb, vc;
                __m128 low, high;
                float  r0, r4;
                va      = _mm256_load_ps(&a[a_i]);
                vb      = _mm256_load_ps(&tb[b_i]);
                vc      = _mm256_mul_ps(va, vb);
                vc      = _mm256_hadd_ps(vc, vc);
                vc      = _mm256_hadd_ps(vc, vc);
                low     = _mm256_extractf128_ps(vc, 0);
                high    = _mm256_extractf128_ps(vc, 1);
                r0      = _mm_cvtss_f32(low);
                r4      = _mm_cvtss_f32(high);
                c[c_i] += r0 + r4;
            }
        }
    }
    t.print("transpose_avx");

    if (true) {
        std::cout << colorant('g', "[PASSED]") << std::endl;
    } else {
        std::cout << colorant('r', "[FAILED]") << std::endl;
    }
}

int main(int argc, char *argv[]) {
    omp_set_num_threads(8);

    try {
        run();
    } catch (const std::exception &e) {
        std::cerr << colorant('y', format_str("error: %s", e.what())) << std::endl;
    }
}

