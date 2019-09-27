// source : https://cp-algorithms.com/data_structures/stack_queue_modification.html

// following is the max queue 

void add(deque<int> &q, int ele)
{
     while(!q.empty() && q.back() < ele)
       q.pop_back();
     
     q.push_back(ele);
}

void del(deque<int> &q, int ele)
{
    if(!q.empty() && q.front() == ele)
      q.pop_front();
}

int getMax(deque<int> &q)
{
    return q.front();
}
