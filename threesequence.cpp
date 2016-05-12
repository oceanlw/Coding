#include <iostream> 
#include <vector>

using std::vector;

vector<int> three_nums(const vector<int> &num)
{
    vector<int> min(num.size()), max(num.size());
    int i;

    if (num.empty()) {
        return {};
    }

    min[0] = 0;
    for (i = 1; i < num.size(); i++)
    {
        if (num[i] < num[i-1]) {
            min[i] = i;
        } else {
            min[i] = min[i-1];
        }
    }
    
    max[num.size()-1] = num.size()-1;
    for (i = num.size()-2; i >= 0; i--)
    {
        if (num[i] > num[i+1]) {
            max[i] = i;
        } else {
            max[i] = max[i+1];
        }
    }

    for (i = 0; i < num.size(); i++)
    {
        if ((num[i] > num[min[i]]) && (num[i] < num[max[i]]))
        {
            return vector<int> {num[min[i]], num[i], num[max[i]]};
        }
    }

    return {};
}

// incorrect!
vector<int> three_nums2(const vector<int> &num)
{
    int i, first = 0, second = -1;

    if (num.empty()) {
      return {};
    }

    for (i = 1; i< num.size(); i++)
    {
        if (second == -1)
        {
            if (num[i] > num[first]) {
                second = i;
            } else if (num[first] > num[i]) {
                first = i;
            }
        }
        else if (num[i] > num[second]) {
            return vector<int> {num[first], num[second], num[i]};
        } else if (num[i] > num[first]) {
            second = i;
        }
    }

    return {};
}

int main(int argc, char **argv)
{
    const vector<int> sequence {4, 7, 5, 1, 3, 8, 9, 6, 2};

    vector<int> sub_seq = three_nums(sequence);

    if (sub_seq.size() == 3) {
        std::cout << "three numbers " << sub_seq[0] << " " << sub_seq[1] << " " << sub_seq[2] << std::endl;
    } else {
        std::cout << "no such sequence" << std::endl;
   }

   sub_seq = three_nums2(vector<int> {4, 7, 5, 1, 2, 3});

    if (sub_seq.size() == 3) {
        std::cout << "three numbers " << sub_seq[0] << " " << sub_seq[1] << " " << sub_seq[2] << std::endl;
    } else {
        std::cout << "no such sequence" << std::endl;
    }
}
