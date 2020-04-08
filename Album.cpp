#include "Album.h"

//Default constructor
Album::Album() {
    artist = "";
    albumTitle = "";
    tracks = std::vector<Track>();
}

//Constructor that takes two strings and a vector of Tracks as parameters.
Album::Album(std::string artist, std::string albumTitle, std::vector<Track> tracks) {
    this->artist = std::move(artist);
    this->albumTitle = std::move(albumTitle);
    this->tracks = std::move(tracks);
}

//Constructor that takes two strings and creates an empty vector of tracks.
Album::Album(std::string artist, std::string albumTitle) {
    this->artist = std::move(artist);
    this->albumTitle = std::move(albumTitle);
    this->tracks = std::vector<Track>();
}

//Getters
const std::string &Album::getArtist() const {
    return artist;
}

const std::string &Album::getAlbumTitle() const {
    return albumTitle;
}

const std::vector<Track> &Album::getTracks() const {
    return tracks;
}

unsigned long Album::getNoTracks() const {
    return tracks.size();
}

//Adds a passed Track to an albums track vector.
void Album::addTrack(const Track &track) {
    this->tracks.push_back(track);
}

std::ostream &operator<<(std::ostream &Str, const Album &albObj) {
    Str << albObj.artist << " : " << albObj.albumTitle << "\n";
    for (auto &t : albObj.tracks) {
        Str << t << "\n";
    }
    return Str;
}

std::istream &operator>>(std::istream &is, Album &albumObj) {
    std::string line;
    std::string albArtist;
    std::string albTitle;
    std::string delim = " : ";
    std::vector<Track> tracks;

    std::getline(is, line);
    albArtist = line.substr(0, line.find(delim));
    line.erase(0, line.find(delim) + delim.length());
    albTitle = line.substr(0);

    albumObj = Album(albArtist, albTitle, tracks);
    return is;
}

bool operator<(const Album &a1, const Album &a2) {
    if (a1.artist != a2.artist) {
        if (a1.artist < a2.artist) {
            return true;
        } else if (a1.artist > a2.artist) {
            return false;
        }
    } else {
        //If the artists are equal we evaluate on album title.
        if (a1.albumTitle < a2.albumTitle) {
            return true;
        } else if (a1.albumTitle > a2.albumTitle) {
            return false;
        }
    }
}

bool operator>(const Album &a1, const Album &a2) {
    if (a1.artist != a2.artist) {
        if (a1.artist > a2.artist) {
            return true;
        } else if (a1.artist < a2.artist) {
            return false;
        }
    } else {
        //If the artists are equal we evaluate on album title.
        if (a1.albumTitle > a2.albumTitle) {
            return true;
        } else if (a1.albumTitle < a2.albumTitle) {
            return false;
        }
    }
}

void Album::testHarness() {
    std::cout << "\n=---Album Test Harness---=" << std::endl;
    Track track = Track("Last Train Home", "00:03:22");
    Track track2 = Track("Uber Everywhere", "00:03:59");
    std::vector<Track> tracks;
    tracks.push_back(track);
    tracks.push_back(track2);
    Album album = Album("The Chats", "Albums Are Cool", tracks);
    Album album2 = Album("Gravy Train", "A Cooler Album");
    Album album3 = Album();
    std::cout << album << std::endl;
    std::cout << "This Album Should Have No Tracks" << std::endl;
    std::cout << album2 << std::endl;
    album2.addTrack(track);
    std::cout << "This Album Should Now Have One Track" << std::endl;
    std::cout << album2 << std::endl;
    std::cout << "This Album Should Be Blank" << std::endl;
    std::cout << album3 << std::endl;
    std::cout << "Operator Should Evaluate To 0" << std::endl;
    std::cout << (album < album2) << std::endl;
    std::cout << "Operator Should Evaluate To 1" << std::endl;
    std::cout << (album > album2) << std::endl;
}
