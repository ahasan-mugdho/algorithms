#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int main() {
    ordered_set s;

    s.insert(5);
    s.insert(2);
    s.insert(10);
    s.insert(7);

    cout << *s.find_by_order(0) << endl;
    cout << *s.find_by_order(2) << endl;

    cout << s.order_of_key(7) << endl;
    cout << s.order_of_key(6) << endl;

    return 0;
}
