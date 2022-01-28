class Solution {
  public:
    
    double calDist(int x1, int y1, int x2, int y2){
        int xDiff = abs(x1-x2);
        int yDiff = abs(y1-y2);
        return sqrt(xDiff*xDiff+yDiff*yDiff);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size()<3)
            return 0;
        int count=0;
        unordered_map<int,unordered_map<double,int>> Map;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                double dist = calDist(points[i][0],points[i][1],points[j][0],points[j][1]);
                Map[i][dist]++;
                Map[j][dist]++;
            }
        }
        
        for(int i=0;i<points.size();i++){
            for(auto iter=Map[i].begin();iter!=Map[i].end();iter++){
                //cout<<iter->first<<" "<<iter->second<<endl;
                if(iter->second>=2)
                    count+= (iter->second)*(iter->second-1);
            }
        }
        return count;
    }
};