You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 

Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20



class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ch1='a', ch2='b';
        int sc=0;
        int cnt1=0,cnt2=0;

        if(x<y)
        {
            swap(ch1,ch2);
            swap(x,y);
        }

        for(char ch:s)
        {
            if(ch==ch1)
            {
                cnt1++;
            }
            else if(ch==ch2)
            {
                if(cnt1>0){
                    cnt1--;
                    sc+=x;
                }
                else
                {
                    cnt2++;
                }
            }
            else{
                sc+=min(cnt1,cnt2)*y;
                cnt1=cnt2=0;
            }
        }
        sc+=min(cnt1,cnt2)*y;
        return sc;
    }
};





//Time Complexity: O(n)
//Space Complexity: O(1)


You are given a string s and two integers x and y:
Remove all "ab" substrings to get x points per occurrence.

Remove all "ba" substrings to get y points per occurrence.

You can remove substrings in any order, but after removing one occurrence, the string shortens. So, the order of removal affects the final score.

✅ Goal
Maximize the total score after removing all possible "ab" or "ba" substrings in some order.

🧠 Strategy / Thought Process
The key observation:

If x > y, it's better to remove all "ab" first (since they give higher points).

If y > x, it's better to remove all "ba" first.

So the code:

Always removes the higher point substring first.

Then processes the rest of the string for the other substring.

🧱 Step-by-Step Explanation of Code
cpp
Copy
Edit
int maximumGain(string s, int x, int y)
s: input string.

x: points for removing "ab".

y: points for removing "ba".

cpp
Copy
Edit
int score = 0;
char ch1 = 'a', ch2 = 'b';
int cnt1 = 0, cnt2 = 0;
score: total points accumulated.

ch1, ch2: used to track which pair we're removing first.

cnt1, cnt2: counters to simulate stack-based pair removal.

🔄 Swap if Needed
cpp
Copy
Edit
if (x < y) {
    swap(x, y);
    ch1 = 'b';
    ch2 = 'a';
}
If "ba" gives more points, we reverse the logic and prioritize "ba" over "ab".
Now ch1-ch2 forms the more valuable pair.

🔁 Loop Through String
cpp
Copy
Edit
for (char ch : s) {
    if (ch == ch1) {
        cnt1++;
    } else if (ch == ch2) {
        if (cnt1 > 0) {
            cnt1--;
            score += x;
        } else {
            cnt2++;
        }
    } else {
        score += min(cnt1, cnt2) * y;
        cnt1 = 0;
        cnt2 = 0;
    }
}
This loop:

Simulates a greedy stack removal of the priority pair (ch1-ch2, i.e., "ab" or "ba").

Tracks partial pairs using counters.

When encountering a non-a or b character (like c), it:

Processes remaining counts into the lower-priority pair (min(cnt1, cnt2) * y).

Resets the counters.

🧾 Final Cleanup
cpp
Copy
Edit
if (cnt1 != 0) {
    score += min(cnt1, cnt2) * y;
}
Handles leftover partial matches after finishing the string (in case string ends with some a’s and b’s).

✅ Summary of Logic
Prioritize the higher scoring pair between "ab" and "ba".

Simulate removal using counters (like a stack).

For each character:

Track and remove the high-score pairs greedily.

Defer the lower-score ones until blocked or done.

At the end or on invalid chars, settle leftover counts for the less valuable pair.

🧠 Time Complexity
O(n) where n is length of the string.

✅ Example
Suppose:

cpp
Copy
Edit
s = "abba", x = 4, y = 5
Since x < y, we swap:

Now x = 5 for "ba", and we look to remove "ba" first.

Process:

a → cnt2++

b → cnt1++

b → cnt1++

a → remove "ba" → cnt1--, score += 5

Now handle leftover: cnt1 = 1, cnt2 = 1 → remove one "ab" → score += 4

Total = 5 + 4 = 9






