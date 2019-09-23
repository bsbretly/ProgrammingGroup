#include <iostream>
#include <vector>
#include <cmath>

class Solution {

public:
    Solution() {
        neigh_ = "neigh";
        horse_count_ = 1;
        count_valid_horses_ = 0;
    }

    int solve(std::string const &sound) {
        if (sound.empty() || sound.length() % 5 != 0) {
            std::cout<<"empty string or non multiple of 5"<<std::endl;
            return -1;
        }
        //count instances of 'n' in sound
        size_t pos = sound.find('n');
        while (pos != std::string::npos) {
            n_indices_.push_back(pos);
            pos = sound.find('n', pos + 1);
        }
        int i = 0;
        while (i < n_indices_.size() - 1) {
            //check if string length is 5
            if (n_indices_[i+1] - n_indices_[i] < 5) horse_count_ += 1;
            i+=1;
        }
        //make sure sound is valid
        for (auto &n_index : n_indices_) {
            int i = n_index; //start at first n index of sound
            int j = 0; //start at beginning of neigh string
            while (j < neigh_.length() && i < sound.length()) {
                if (sound[i] == neigh_[j]) {
                    //follow neigh string until there is a mismatch
                    j+=1;
                    i+=1;
                }
                //when the strings mismitch, go to next sound index
                else i+=1;
            }
            if (j == neigh_.length()) {
                count_valid_horses_ += 1;
//                std::cout<<"count_valid_horses_ = "<<count_valid_horses_<<std::endl;
            }
        }
//        std::cout<< floor(sound.length()/5) <<std::endl;
//        std::cout<<"count_valid_horses_ = "<<count_valid_horses_<<std::endl;
        if (count_valid_horses_ != floor(sound.length()/5)) {
//            std::cout<<"in count_valid_horses check"<<std::endl;
            return -1;
        }
        return horse_count_;
    }

private:
    std::string neigh_;
    std::vector<int> n_indices_;
    int horse_count_;
    int count_valid_horses_;
};

int main() {
    Solution horseNeigh;
    std::cout<<horseNeigh.solve("neigneighh")<<std::endl;
    return 0;
}