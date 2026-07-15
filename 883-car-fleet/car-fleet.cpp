class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        int n = speed.size();

        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.rbegin(), car.rend());
        double mx_time = 0;
        int fleets = 0;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - car[i].first) / car[i].second;
            if (time > mx_time) {
                fleets++;
                mx_time = time;
            }
        }
        return fleets;
    }
};