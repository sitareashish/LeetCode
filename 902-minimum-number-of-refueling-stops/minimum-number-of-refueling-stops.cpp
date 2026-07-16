class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max-heap to store the fuel capacities of stations we have passed
        priority_queue<int> max_heap;
        
        int stops = 0;
        int current_fuel = startFuel;
        int current_position = 0;
        
        // Add the target as a dummy final station with 0 fuel
        stations.push_back({target, 0});
        
        for (const auto& station : stations) {
            int next_position = station[0];
            int fuel_available = station[1];
            
            int distance_to_travel = next_position - current_position;
            
            // If we don't have enough fuel to reach the next station,
            // retroactively refuel from the best stations we passed.
            while (current_fuel < distance_to_travel) {
                if (max_heap.empty()) {
                    return -1; // Cannot reach the next station
                }
                current_fuel += max_heap.top();
                max_heap.pop();
                stops++;
            }
            
            // Move to the next station
            current_fuel -= distance_to_travel;
            current_position = next_position;
            
            // Put this station's fuel into our max-heap for future use
            max_heap.push(fuel_available);
        }
        
        return stops;
    }
};