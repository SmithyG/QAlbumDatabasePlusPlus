#ifndef CW2_TRACK_H
#define CW2_TRACK_H

#include "Utils.h"
#include "Duration.h"

class Track {
public:
    static void testHarness();

    Track();

    Track(std::string title, std::string duration);

    Track(std::string title, Duration dur);

    friend std::ostream &operator<<(std::ostream &Str, const Track &trackObj);

    friend std::istream &operator>>(std::istream& is, Track& trackObj);

    const std::string &getTitle() const;

    const Duration &getDuration() const;

private:
    std::string title;
    Duration duration;
};


#endif //CW2_TRACK_H
