#include "./util.hpp"

using namespace cc;

void run() {
    std::cout << "hello world!" << std::endl;
}

int main(int argc, char *argv[]) {
    omp_set_num_threads(8);

    try {
        run();
    } catch (const std::exception &e) {
        std::cerr << colorant('y', format_str("error: %s", e.what())) << std::endl;
    }
}

