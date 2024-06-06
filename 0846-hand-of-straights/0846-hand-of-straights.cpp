class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if( n%groupSize != 0)
            return false;
        map<int,int> count;
        for(int i = 0; i<n;i++){
            count[hand[i]]++;
        }

        
       for(auto it=count.begin();it!=count.end();)
		{
			if(it->second>0)
			{
				for(int i=0;i<groupSize;i++)
				{
					if(count[it->first+i]>0)
					{
						count[it->first+i]--;
					}
					else
						return false;
				}
			}
			else
				it++;
		}
        return true;
            }
};