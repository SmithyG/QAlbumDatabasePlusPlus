#ifndef CW2_DURATION_H
#define CW2_DURATION_H

#include "Utils.h"

class Duration {
public:
    static void testHarness();

    Duration();

    Duration(int hours, int minutes, int seconds);

    explicit Duration(std::string duration);

    friend std::ostream &operator<<(std::ostream &Str, const Duration &durObj);

    friend std::istream &operator>>(std::istream& is, Duration& durObj);

    bool operator<(const Duration &rhs) const;

    bool operator>(const Duration &rhs) const;

    bool operator<=(const Duration &rhs) const;

    bool operator>=(const Duration &rhs) const;

    bool operator==(const Duration &rhs) const;

    bool operator!=(const Duration &rhs) const;

    void add(Duration d2);

    void format();

    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    int getTotal() const;

private:
    int hours;
    int minutes;
    int seconds;
};


#endif //CW2_DURATION_H
