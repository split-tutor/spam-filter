// spamfilter.h - header file for spam filter

#include <iostream>
#include <string>
#include <fstream>

// SpamFilter - reads file from the source, filters lines that contain 
// blacklistd words, and writes outputs to target file.
struct SpamFilter {
    // Blacklisted keywords
    std::string exclude[10];

    // Simple statistics
    int totalLines;
    int filteredLines;

    SpamFilter() : totalLines(0), filteredLines(0) {}

    // Set blacklist keywords
    void setBlacklist(const std::string* blklst);

    // Main working function
    int filter(std::string src, std::string tgt);
};

void SpamFilter::setBlacklist(const std::string* blklst)
{
    // TODO: Set blacklist keywords
}

int SpamFilter::filter(std::string src, std::string tgt)
{
    // TODO:
    //     1. Read files from src
    //     2. If a line contains words in `blacklist`, throw away that line
    //     3. Writes outputs to tgt
    //     4. Update spam filter statistics
    // return:
    //     -1; if error occurs (cannot open files, etc.)
    //     n; number of lines written to the target file

    std::ifstream ifs{src};
    if (!ifs) {
        std::cerr << "Cannot open src\n";
        return -1;
    }

    std::ofstream ofs{tgt};
    if (!ofs) {
        std::cerr << "Cannot open tgt\n";
        return -1;
    }

    // Read lines from the src. You may need to use while loop to read all
    // lines, and `ifs.eof()` to  determine _End Of File_.
    std::string line;
    std::getline(ifs, line);

    // TODO: Implement spam filtering
    
    // TODO: Writes only good sentences  to the tgt
    ofs << line << '\n'; 
    
    // TODO: Update statistics of your spam filter, i.e. number of total lines
    // and filtered lines

    // Don't forget to close the file streams
    ifs.close();
    ofs.close();
}

std::ostream& operator<<(std::ostream& os, const SpamFilter& s)
{
    // TODO: Implement overloaded version of operator<< for spam filter
    // You should format your output to include blacklist keywords,
    // total number of read/written lines, etc.

    os << "Awesome spam filter";

    return os;
}