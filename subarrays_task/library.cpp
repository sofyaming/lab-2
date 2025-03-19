#include "library.hpp"
#include <iostream>

    int longest_duplicate_subarray(const std::vector<int>& nums) {
        /*if (nums.size() < 2) {
            return 0;
        }*/
        // Инициализация границ бинарного поиска
        int low = 1;
        int high = nums.size() - 1;
        int max_length = 0;

        // Бинарный поиск по длине подмассива
        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::unordered_set<std::string> seen_subarrays;
            bool duplicate_found = false;

            // Проверка всех подмассивов длины mid
            for (int i = 0; i <= static_cast<int>(nums.size()) - mid; ++i) {
                // 1. Создайте строковое представление подмассива
                //    Формат: "элемент1,элемент2,...,элементN"
                //    Пример: для {2,3,4} -> "2,3,4,"
                std::string subarray_str;

                // 2. Заполните subarray_str значениями подмассива [i..i+mid)
                //    (реализуйте цикл)
                for (int j = i; j < i + mid; ++j) {
                    subarray_str += std::to_string(nums[j]) + ",";
                }

                // 3. Проверьте наличие подмассива в сете
                if (seen_subarrays.count(subarray_str) > 0) {
                    duplicate_found = true;
                    break;
                }
                // 4. Добавьте подмассив в сет
                seen_subarrays.insert(subarray_str);
                
            }

            // Обновление границ бинарного поиска
            if (duplicate_found) {
                max_length = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return max_length;
    }
    int main() {
        //test1
        // Простой случай
        std::vector<int> nums1 = { 1, 2, 3, 4, 2, 3, 4, 5 };
        int result1 = longest_duplicate_subarray(nums1);
        // Все элементы одинаковые
        std::vector<int> nums2 = { 5, 5, 5, 5 };
        int result2 = longest_duplicate_subarray(nums2);
        // Дубликаты перекрываются
        std::vector<int> nums3 = { 1, 2, 1, 2, 1, 2};
        int result3 = longest_duplicate_subarray(nums3);

        std::cout << result1 << "\n"<<result2<<"\n" <<result3<<"\n";

        //test2
        // Минимальная длина массива
        std::vector<int> nums4 = { 1 };
        int result4 = longest_duplicate_subarray(nums4);
        std::vector<int> nums5 = { 1, 1 };
        int result5 = longest_duplicate_subarray(nums5);
        // Нет дубликатов
        std::vector<int> nums6 = {1, 2, 3, 4, 5};
        int result6 = longest_duplicate_subarray(nums6);
        // Максимальный дубликат в конце
        std::vector<int> nums7 = {1, 2, 3, 1, 2, 3};
        int result7 = longest_duplicate_subarray(nums7);

        std::cout << result4 << "\n" << result5 << "\n" << result6 << "\n"<<result7<<"\n";

        //test3
        // Чередование элементов
        std::vector<int> nums8 = { 1, 2, 1, 2, 3, 1, 2 };// 2
        int result8 = longest_duplicate_subarray(nums8);
        // Дубликаты из одного элемента
        std::vector<int> nums9 = {1, 2, 2, 3, 3, 4};
        int result9 = longest_duplicate_subarray(nums9);
        // Дубликаты с отрицательными числами
        std::vector<int> nums10 = {-1, 0, -1, 0};
        int result10 = longest_duplicate_subarray(nums10);

        std::cout << result8 << "\n" << result9 << "\n" << result10 << "\n";

        //test4
        // Большой массив (10^5 элементов) - для проверки O(n log n)
        std::vector<int> big_array(100000, 7);
        int result11 = longest_duplicate_subarray(big_array);
        // Паттерн: 1,2,3,4 повторяется 25000 раз
        std::vector<int> pattern;
        for (int i = 0; i < 25000; ++i) {
            pattern.insert(pattern.end(), { 1,2,3,4 });
        }
        int result12 = longest_duplicate_subarray(pattern); // 99996

        std::cout << result11 << "\n" << result12 << "\n";
    }
