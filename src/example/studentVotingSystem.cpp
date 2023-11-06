#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
    string name;
    int id;
    int vote;
};

class VotingSystem
{
public:
    vector<string> candidates;
    vector<int> votes;
    vector<Student> students;

    void addCandidate(string candidateName)
    {
        candidates.push_back(candidateName);
        votes.push_back(0);
    }

    void vote(int candidateIndex, int studentId)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].id == studentId)
            {
                students[i].vote = candidateIndex;
                votes[candidateIndex]++;
                break;
            }
        }
    }

    void addStudent(string studentName, int studentId)
    {
        Student student;
        student.name = studentName;
        student.id = studentId;
        student.vote = -1;
        students.push_back(student);
    }

    const string getWinner()
    {
        int maxVotes = *max_element(votes.begin(), votes.end());
        int winnerIndex = find(votes.begin(), votes.end(), maxVotes) - votes.begin();
        return candidates[winnerIndex];
    }
};

int main()
{
    VotingSystem vs;
    vs.addCandidate("John");
    vs.addCandidate("Jane");
    vs.addStudent("Alice", 1);
    vs.addStudent("Bob", 2);
    vs.vote(0, 1);
    vs.vote(1, 2);
    vs.vote(0, 2);
    cout << "Winner: " << vs.getWinner() << endl;
    return 0;
}
