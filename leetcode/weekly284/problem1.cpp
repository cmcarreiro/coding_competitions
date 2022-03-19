class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indexes;
        set<int> k_distant_indexes_set;
        vector<int> k_distant_indexes_vector;

        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == key) {
                indexes.push_back(i);
            }
        }

        for (int index : indexes ) {
            for (int j = 0; j < nums.size(); j++ ) {
                if ( abs(j - index) <= k) {
                    k_distant_indexes_set.insert(j);
                }
            }
        }

        for (int k_distant_index : k_distant_indexes_set) {
            k_distant_indexes_vector.push_back(k_distant_index);
        }

        return k_distant_indexes_vector;
    }
};