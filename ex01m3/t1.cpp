#include <iostream>

/*A popular restaurant has just opened in our town. This restaurant has exactly N
seat, numbered 1 to N. This restaurant is also very sophisticated such that there are N
chef, each exclusively attends to exactly one particular seat, i.e., the chef number i will
serve exclusively at seat number i. These chefs have different styles, we know that if a
customer is served by the chef number i, that customer will finish his/her meal in exactly
Ti minutes.

At the beginning of the day, there are some customers waiting in a queue to be
served. As soon as any seat is available at time X, the customer at the front of the queue
will rush in to the first available chef. Assume that that customer is seated at the seat
number i, the customer will finished the meal at time X + Ti and the customer at the front
of the queue at that time will immediately rush in to that seat as well.
This restaurant is very popular such that there are very large number of customer.
However, their number of chef is not that many. Hence, each customer hast to wait for a
very long time. Some customers want to visit somewhere else and come back to the
restaurant before their seating time. Your task is to calculate the time that these
customers have to be seated, assuming that the restaurant open at time 0. Hence, the
first N customer will be seated at time 0, the N+1 customer will be seated as soon as the
fastest chef finished his/her first customer and so on. */


/*Input
• The first line contains two integers N, and A (1 ≤ N ≤ 1,000 and 1 ≤ A ≤ 200)
• The second line contains N integers, indicating Ti, starting from T1 to TN. (1≤ Ti ≤
1,000)
• The third line contains A integers. These integers are c1… cA, each integer indicates
the label of the customer that we want to know their seating time. (1≤ ci ≤ 1012)*/

// define long long as ll
typedef long long ll;
int N, A;
ll arr[1000] = {0};
ll target;

/*
Output
The output contains A lines. The i-th line indicates the time that the customer ci is
seated. Be noted that this value can be larger than 32 bit integer*/

ll process(ll target) {

}

int main(){
    std::cin >> N >> A;
    for (int i = 0 ; i < N ; ++i) std::cin >> arr[i];

    for (int i = 0 ; i < A ; ++i) {
        std::cin >> target;
        std::cout << process(target) << std::endl;
    }
    return 0;
}
