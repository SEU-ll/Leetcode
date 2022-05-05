# Two Sum 

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        //暴力解法
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){//数组中同一个元素在答案里不能重复出现
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};*/
        //哈希表求解两数之和，根据题目条件利用无序的map结构
        unordered_map<int,int> map;//注意下面是逐步把数组元素映射到map里，for循环开始的时候map里没有元素
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){//定义的容器指针第一次是不执行if语句的，因为容器里没有元素
                return {iter->second,i};
            }
            //map.insert(pair<int,int>(nums[i],i));//往容器里添加元素，直到map里找到和为目标值的两个数
            map.insert({nums[i], i});
        }
        return {};
    }
};
```
