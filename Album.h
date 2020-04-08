#ifndef CW2_ALBUM_H
#define CW2_ALBUM_H

#include "Utils.h"
#include "Track.h"

class Album {
public:
    static void testHarness();

    Album();

    Album(std::string artist, std::string albumTitle, std::vector<Track> tracks);

    Album(std::string artist, std::string albumTitle);

    void addTrack(const Track &track);

    friend std::ostream &operator<<(std::ostream &Str, const Album &durObj);

    friend std::istream &operator>>(std::istream& is, Album& albumObj);

    friend bool operator< (const Album &a1, const Album &a2);

    friend bool operator> (const Album &a1, const Album &a2);

    const std::string &getArtist() const;

    const std::string &getAlbumTitle() const;

    const std::vector<Track> &getTracks() const;

    unsigned long getNoTracks() const;

private:
    std::string artist;
    std::string albumTitle;
    std::vector<Track> tracks;
};


#endif //CW2_ALBUM_H
