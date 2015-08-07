#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<iomanip>
using namespace std;
ifstream fin;
ofstream fout;
bool greater_than(int i ,int j) {return i>j;}
int main()
{
    priority_queue<int,std::vector<int>, std::greater<int> > min_heap;
    priority_queue<int,std::vector<int>, std::less<int> > max_heap;
    fin.open("input.txt");
    fout.open("output.txt");
    vector<int> first,second;
    int N,tmp;
    float median;
    fin>>N;
    for(int i=0;i<N;i++)
    {
        fin>>tmp;
        if(max_heap.empty())
        {
            max_heap.push(tmp);
            median = tmp;
        }
        else{
        if(i%2 == 0)                {
                        if(tmp<=max_heap.top())
                        {
                                max_heap.push(tmp);
                                tmp = max_heap.top();
                                max_heap.pop();
                        }
                        else if(tmp> min_heap.top())
                        {
                                min_heap.push(tmp);
                                tmp = min_heap.top();
                                min_heap.pop();

                        }

                        median =(float) tmp ;median =(float) median/1.0;
                }
            else
                {
                       if(min_heap.empty())                        {
                            if(tmp < max_heap.top())
                            {
                                    max_heap.push(tmp);
                                    min_heap.push(max_heap.top());
                                    max_heap.pop();

                            }
                            else  min_heap.push(tmp);
                        }
                        else
                        {
                                    if(tmp<= median)
                                    {
                                        max_heap.push(tmp); min_heap.push(median);
                                    }
                                    else
                                    {
                                        min_heap.push(tmp); max_heap.push(median);
                                    }
                        }
                   // cout<<"/////////////////"<<max_heap.top()<<"/////////////"<<min_heap.top()<<"/////////\n";
                    median = (float)(max_heap.top() + min_heap.top())/2;
                    //cout<<"======================================"<<endl;
            }}
        fout<<median<<endl;
    }
}
