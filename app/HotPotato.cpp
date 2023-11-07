#include "HotPotato.hpp"
#include "QueueOfStrings.hpp"

#include <istream>  
#include <vector>

// You may want to #include others that we have talked about
#include <string>
#include <sstream>


std::string playHotPotato(std::istream &in, const std::vector<unsigned> & numOfPasses)
{
    // Initialize line for name
    std::string line, name;
    std::stringstream ss;

    // Initialize a QueueOfStrings to hold names
    QueueOfStrings names;
    
    // Loop through each line in the text file
    while(getline(in, line))
    {
        // Get the string in the line
        ss.str(line);
        // Add lines as string names to the QueueOfStrings
        while(ss >> name)
        {
            names.enqueue(name);
        }
        ss.clear();
    }

    // Initialize round counter
    unsigned round = 0;

    // Pass the potato until only one person remains
    while (names.size() > 1)
    {
        // Initialize passes for each round
        unsigned passes = numOfPasses[round % numOfPasses.size()]; // remainder of round / numOfPasses size is the index of the value of passes of the round
        // Passes the potato around, whoever is at the front after the loop is eliminated
        for (unsigned i = 0; i < passes; ++i)
        {
            // Enqueue whoever is in front, Remove the name from the front of the queue
            names.enqueue(names.front());
            names.dequeue();
        }

        // Remove the name at the front (they have the potato in the end)
        names.dequeue();

        // Increment round
        round ++;
    }
    // Return winner
    return names.front();
}
