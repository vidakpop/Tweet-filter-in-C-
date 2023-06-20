#include <iostream>

#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    // Create a vector to store banned words
    vector<string> bannedWords;
    string word;
    
    // Open the file containing banned words
    ifstream inFile("bannedWords.txt");

    if (inFile.is_open())
    {



        // Read each word from the file and add it to the vector
        while (getline(inFile, word))
        {
            bannedWords.push_back(word);
        }
        inFile.close();
    }

    // Create arrays to store tweet file names and filtered tweet file names
    string tweetFiles[] = {"tweets1.txt", "tweets2.txt", "tweets3.txt", "tweets4.txt"};
    string filteredTweetFiles[] = {"tweets1Filtered.txt", "tweets2Filtered.txt", "tweets3Filtered.txt", "tweets4Filtered.txt"};

    // Loop through each tweet file
    for (int i = 0; i < 4; i++)
    {
        // Open the tweet file and filtered tweet file
        ifstream tweetFile(tweetFiles[i]);
        ofstream filteredTweetFile(filteredTweetFiles[i]);

        if (tweetFile.is_open() && filteredTweetFile.is_open())
        {
            string tweet;
            // Read each tweet from the tweet file
            while (getline(tweetFile, tweet))
            {
                // Loop through each banned word
                for (int j = 0; j < bannedWords.size(); j++)
                {
                    // Find the position of the banned word in the tweet
                    size_t found = tweet.find(bannedWords[j]);
                    if (found != string::npos)
                    {
                        // Replace the banned word with asterisks
                        int len = bannedWords[j].length();
                        tweet.replace(found + 1, len - 2, len - 2, '*');
                    }
                }
                // Write the filtered tweet to the filtered tweet file
                filteredTweetFile << tweet << endl;
            }
            // Close both files
            tweetFile.close();
            filteredTweetFile.close();
        }
    }

    return 0;
}