#include <iostream>

int64_t** create_pascal_triangle(int32_t);
void print_left_aligned(int64_t**, int32_t);
void free_memory(int64_t**, int32_t);

int main() {
    try {
        int32_t rows{};
        std::cout << "Введите количество строк: ";
        std::cin >> rows;
        
        if (rows <= 0) {
            throw std::invalid_argument("Ошибка: требуется положительное число строк (>0)");
        }
        
        int64_t** triangle = create_pascal_triangle(rows);
        print_left_aligned(triangle, rows);
        free_memory(triangle, rows);
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n'; 
        return 1;
    }
    return 0;
}

int64_t** create_pascal_triangle(int32_t rows) {
    int64_t** triangle = new int64_t*[rows];
    for(int32_t i = 0; i < rows; i++) {
        triangle[i] = new int64_t[i+1];
        triangle[i][0] = 1; 
        triangle[i][i] = 1;   
        
        for(int32_t j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}

void print_left_aligned(int64_t** triangle, int32_t rows) {
    for(int32_t i = 0; i < rows; i++) {
        for(int32_t j = 0; j <= i; j++) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void free_memory(int64_t** triangle, int32_t rows) {
    for(int32_t i = 0; i < rows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}