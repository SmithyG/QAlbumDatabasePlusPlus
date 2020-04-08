#include "Duration.h"

//Default constructor
Duration::Duration() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

//Assigns duration variables by passed ints
Duration::Duration(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format();
}

//Allows a string in HH:MM:SS to be passed and stored as ints to create a Duration object
Duration::Duration(std::string duration) {
    //Specify the delimiter
    std::replace(duration.begin(), duration.end(), ':', ' ');

    //Create a vector to store the ints
    std::vector<int> tempVec;
    std::stringstream ss(duration);
    int temp;
    //Loop through the stringstream to find ints to delimit
    while (ss >> temp)
        tempVec.push_back(temp);

    hours = tempVec[0];
    minutes = tempVec[1];
    seconds = tempVec[2];
    //Format the duration
    this->format();
}

//Accepts another Duration object as a parameter to add to the original object
void Duration::add(Duration d2) {
    if (seconds + d2.seconds >= 60) {
        minutes += ((seconds + d2.seconds) /
                    60); //Finds out the amount of extra minutes and adds that result to the minutes variable
        seconds = ((seconds + d2.seconds) % 60); //Finds out the remainder to set the new seconds
    } else {
        seconds += d2.seconds;
    }

    if (minutes + d2.minutes >= 60) {
        hours += ((minutes + d2.minutes) /
                  60); //Finds out the amount of extra hours and adds that result to the hours variable
        minutes = ((minutes + d2.minutes) % 60); //Finds out the remainder to set the new minutes
    } else {
        minutes += d2.minutes;
    }
    hours += d2.hours;
}

//Formats a duration into correct HH:MM:SS format
void Duration::format() {
    if (seconds >= 60) {
        minutes += (seconds / 60);
        seconds = (seconds % 60);
    }
    if (minutes >= 60) {
        hours += (minutes / 60);
        minutes = (minutes % 60);
    }
}

//Converts a Duration object into a string representation.
std::ostream &operator<<(std::ostream &Str, const Duration &durObj) {
    return Str << std::setw(2) << std::setfill('0') << durObj.hours << ":" << std::setw(2)
               << std::setfill('0') << durObj.minutes << ":" << std::setw(2) << std::setfill('0')
               << durObj.seconds;
}

bool Duration::operator<(const Duration &rhs) const {
    return this->getTotal() < rhs.getTotal();
}

bool Duration::operator>(const Duration &rhs) const {
    return rhs.getTotal() < this->getTotal();
}

bool Duration::operator<=(const Duration &rhs) const {
    if (rhs.getTotal() == this->getTotal()) {
        return true;
    } else {
        return this->getTotal() < rhs.getTotal();
    }
}

bool Duration::operator>=(const Duration &rhs) const {
    if (rhs.getTotal() == this->getTotal()) {
        return true;
    } else {
        return rhs.getTotal() < this->getTotal();
    }
}

bool Duration::operator==(const Duration &rhs) const {
    return this->getTotal() == rhs.getTotal();
}

bool Duration::operator!=(const Duration &rhs) const {
    return this->getTotal() != rhs.getTotal();
}

//Gets the total duration (Concatenated attributes) of a duration object, used for comparison of Duration objects.
int Duration::getTotal() const {
    std::string tot = "" + std::to_string(hours) + std::to_string(minutes) + std::to_string(seconds);
    int total = std::stoi(tot);
    return total;
}

//Getters
int Duration::getHours() const {
    return hours;
}

int Duration::getMinutes() const {
    return minutes;
}

int Duration::getSeconds() const {
    return seconds;
}

//Takes input for a duration object in the format HH:MM:SS
std::istream &operator>>(std::istream &is, Duration &durObj) {
    char c1, c2;
    int hours, minutes, seconds;
    if (is >> hours >> c1 >> minutes >> c2 >> seconds) {
        if (c1 == ':' && c2 == ':') {
            durObj = Duration(hours, minutes, seconds);
        } else {
            is.clear(std::ios_base::failbit);
        }
    } else {
        is.clear(std::ios_base::failbit);
    }
    return is;
}

void Duration::testHarness() {
    std::cout << "\n=---Duration Test Harness---=" << std::endl;
    Duration dur = Duration();
    Duration dur2 = Duration(1, 2, 3);
    Duration dur3 = Duration("00:03:22");
    Duration dur4 = Duration("00:10:22");
    std::cout << dur << std::endl;
    std::cout << dur3 << std::endl;
    std::cout << "Hours: " << dur2.getHours() << " Minutes: " << dur2.getMinutes() << " Seconds: " << dur2.getSeconds()
              << "\n";
    dur2.add(dur3);
    std::cout << dur2 << std::endl;
    std::cout << dur2.getTotal() << std::endl;
    std::string testString = "00:03:22";
    std::stringstream ss(testString);
    Duration testDur;
    ss >> testDur;
    std::cout << (testDur) << std::endl;
    std::cout << "All These Relational Operators Should Evaluate To 1" << std::endl;
    std::cout << (dur4 != dur3) << std::endl;
    std::cout << (dur3 < dur4) << std::endl;
    std::cout << (dur4 > dur3) << std::endl;
    std::cout << (dur4 == dur4) << std::endl;
    std::cout << "All These Relational Operators Should Evaluate To 0" << std::endl;
    std::cout << (dur4 != dur4) << std::endl;
    std::cout << (dur4 < dur3) << std::endl;
    std::cout << (dur3 > dur4) << std::endl;
    std::cout << (dur3 == dur4) << std::endl;
}
