#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <iostream>

using namespace std;

unordered_map<string, int> emailToId;
unordered_map<int, string> idToName;
unordered_map<int, int> emailGroup;

void join(unordered_map<int, int>& emailGroup, int first, int second);
int find(unordered_map<int, int>& emailGroup, int id);
vector<vector<string>> accountMerge(vector<vector<string>>& accounts);

void join(unordered_map<int, int>& emailGroup, int first, int second) {
    int left_id = find(emailGroup, first);
    int right_id = find(emailGroup, second);
    if (left_id != right_id) {
        emailGroup[left_id] = right_id;
    }
}

int find(unordered_map<int, int>& emailGroup, int id) {
    while (id != emailGroup[id]) {
        id = emailGroup[id];
    }
    return id;
}

vector<vector<string>> accountMerge(vector<vector<string>>& accounts) {
    for (int i = 0; i < accounts.size(); i++) {
        auto& account = accounts[i];
        string name = account[0];
        idToName[i] = name;
        emailGroup[i] = i;
        for (int j = 1; j < account.size(); j++) {
            string email = account[j];
            if (emailToId.find(email) == emailToId.end()) {
                emailToId[name] = i;
            } else {
                join(emailGroup, i, emailToId[email]);
            }
        }
    }
    unordered_map<int, set<string>> res;
    for (int i = 0; i < accounts.size(); i++) {
        auto& account = accounts[i];
        int id = find(emailGroup, i);
        res[id].insert(account.begin() + 1, account.end());
    }

    vector<vector<string>> out;
    for (auto& item : res) {
        vector<string> output_item(item.second.begin(), item.second.end());
        output_item.insert(output_item.begin(), idToName[item.first]);
        out.push_back(output_item);
    }
    return out;
}

int main() {
    return 0;
}
