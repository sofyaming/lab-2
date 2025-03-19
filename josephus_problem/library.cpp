#include "library.hpp"
#include <iostream>

    int josephus_problem(const std::vector<int>& nums, int k) {

        std::deque<int> circle(nums.begin(), nums.end());

        while (circle.size() > 1) {
            
            for (int i = 1; i < k; ++i) {
                int front_element = circle.front();
                circle.pop_front();
                circle.push_back(front_element);
            }
            
            circle.pop_front();
        }

        return circle.front();
        
    }

    int main() {
        //test1
        // Пример из условия
        std::vector<int> nums1 = { 1, 2, 3, 4, 5, 6, 7 };
        int last1 = josephus_problem(nums1, 3);
        // K=1 (удаление по порядку)
        std::vector<int> nums2 = { 1, 2, 3, 4};
        int last2 = josephus_problem(nums2, 1);
        // K превышает размер массива
        std::vector<int> nums3 = { 1, 2, 3};
        int last3 = josephus_problem(nums3, 5);
        
        std::cout << last1<<"\n"<<last2<<"\n"<<last3<<"\n";


        //test2
        // Массив из одного элемента
        std::vector<int> nums4 = {42};
        int last4 = josephus_problem(nums4, 10);
        // K=2, чётный размер
        std::vector<int> nums5 = { 1, 2, 3, 4 };
        int last5 = josephus_problem(nums5, 2);

        std::cout << last4 << "\n" << last5 << "\n";

        //test3
        // K=2, нечётный размер
        std::vector<int> nums6 = {1, 2, 3, 4, 5 };
        int last6 = josephus_problem(nums6, 2);
        // Все элементы удаляются за один круг
        std::vector<int> nums7 = { 1, 2, 3, 4 };
        int last7 = josephus_problem(nums7, 4);

        std::cout << last6 << "\n" << last7 << "\n";

        // Проверка для большого N
        std::vector<int> big_array(1000);
        for (int i = 0; i < 1000; ++i) {
            big_array[i] = i + 1;
        }
        int last8 = josephus_problem(big_array, 7);
        std::cout << last8 << "\n";
    }
