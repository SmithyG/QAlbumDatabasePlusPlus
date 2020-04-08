#include "Track.h"

//Default constructor
Track::Track() {
    title = "";
    duration = Duration();
}

//Constructor that takes two strings to create a track
Track::Track(std::string title, std::string duration) {
    this->title = std::move(title);
    this->duration = Duration(std::move(duration));
}

//Constructor that takes a title string and a duration object to create a track.
Track::Track(std::string title, Duration dur) {
    this->title = std::move(title);
    this->duration = dur;
}

//Getters
const std::string &Track::getTitle() const {
    return title;
}

const Duration &Track::getDuration() const {
    return duration;
}

std::istream &operator>>(std::istream &is, Track &trackObj) {
    char delim;
    std::string s1;
    std::string restOfLine;
    std::string title;
    Duration dur;
    std::string trackLine;
    if (is >> dur >> delim >> s1) {
        if (delim == '-') {
            //getline is needed in case the track title contains a space character.
            std::getline(is, restOfLine);
            title = s1 + restOfLine;
            trackObj = Track(title, dur);
        } else {
            is.clear(std::ios_base::failbit);
        }
    } else {
        is.clear(std::ios_base::failbit);
    }
    return is;
}

std::ostream &operator<<(std::ostream &Str, const Track &trackObj) {
    return Str << trackObj.duration << " - " << trackObj.title;
}

void Track::testHarness() {
    std::cout << "\n=---Track Test Harness---=" << std::endl;
    Track track = Track("Last Train Home", "00:03:22");
    Track track2 = Track();
    Duration dur = Duration(0, 3, 14);
    Track track3 = Track("Alien Boy", dur);
    std::cout << track << std::endl;
    std::cout << track2 << std::endl;
    std::cout << track3 << std::endl;
    std::string testString = "00:04:02 - Test Track";
    std::stringstream ss(testString);
    Track testTrack;
    ss >> testTrack;
    std::cout << "Title: " << testTrack.getTitle() << "\nDuration: " << testTrack.getDuration() << std::endl;
}
