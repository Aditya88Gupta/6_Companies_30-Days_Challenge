class Solution {
    double x,y,r;
public:
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
     double random(){
        return 1.0 * rand() / RAND_MAX;
    }
    
    vector<double> randPoint() {
        double length = sqrt(random()) * r;
        double angle = random() * 2 * M_PI;
        double xRand = x + length * cos(angle);
        double yRand = y + length * sin(angle);
        return {xRand, yRand};
    }
};