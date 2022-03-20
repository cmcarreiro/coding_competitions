#include <stdio.h>
#include <map>

void sort_treats(int test_case, int amount_pets) {
    std::map<int, int> size_to_treats;
    int amount_treats = 0;
    int multiplicator = 1;
    
    
    for (int i = 0; i < amount_pets; i++) {
        int size_of_pet;
        scanf("%d", &size_of_pet);
        
        //if it exists in the map, we increase its count
        if (size_to_treats.count(size_of_pet) > 0) {
            (size_to_treats.find(size_of_pet))->second++;
        } else {
            size_to_treats.insert(std::make_pair(size_of_pet, 1));
        }
    }
    
    for (const auto& elem: size_to_treats) {
        amount_treats += elem.second * multiplicator;
        multiplicator++;
    }
    
    printf("Case #%d: %d", test_case + 1, amount_treats);
}

int main() {
    int num_cases;
    
    scanf("%d", &num_cases);
    
    for (int i = 0; i < num_cases; i++) {
        int amount_pets;
        scanf("%d", &amount_pets);
        sort_treats(i, amount_pets);
        if (i != num_cases - 1) printf("\n");
    }
    
    return 0;
}