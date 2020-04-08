#include "Collection.h"

//Default constructor
Collection::Collection() {
    albums = std::vector<Album *>();
}

//Constructor that takes a vector of Album pointers as parameter.
Collection::Collection(std::vector<Album *> albums) {
    this->albums = std::move(albums);
}

const std::vector<Album *> &Collection::getAlbums() const {
    return albums;
}

//Adds an album to the collection and returns a pointer to the album.
Album *Collection::addAlbum(Album *albPointer) {
    this->albums.push_back(albPointer);
    return this->albums[albums.size() - 1];
}

Duration Collection::pinkFloyd() {
    std::vector<Track> allTracks;
    //Find all Pink Floyd albums and add all tracks belonging to Pink Floyd albums to allTracks vector.
    for (int i = 0; i < albums.size(); i++) {
        if (albums[i]->getArtist() == "Pink Floyd") {
            for (auto &t : albums[i]->getTracks()) {
                allTracks.push_back(t);
            }
        }
    }
    //Add all Pink Floyd tracks to a blank duration object
    Duration totDuration = Duration();
    for (int j = 0; j < allTracks.size(); j++) {
        totDuration.add(allTracks.at(j).getDuration());
    }
    std::cout << "---The Total Duration Of All Pink Floyd Albums is:---" << std::endl;
    return totDuration;
}

Track Collection::longestTrack() {
    std::vector<Track> allTracks;
    //Add all tracks in collection to a vector allTracks.
    for (int i = 0; i < albums.size(); i++) {
        for (auto &t : albums[i]->getTracks()) {
            allTracks.push_back(t);
        }
    }
    //Iterate over the vector to find the longest Track.
    Track largestTrack = allTracks.at(0);
    for (int j = 1; j < allTracks.size(); j++) {
        if (allTracks.at(j).getDuration() > largestTrack.getDuration()) {
            largestTrack = allTracks.at(j);
        }
    }
    std::cout << "\n---The Longest Track Is:---" << std::endl;
    return largestTrack;
}

//Finds the album with the largest number of tracks.
Album Collection::mostTracks() {
    Album mostTracks = Album();
    for (auto &a : albums) {
        if (a->getTracks().size() > mostTracks.getTracks().size()) {
            mostTracks = *a;
        }
    }
    std::cout << "\n---The Album With The Most Tracks Is:---" << std::endl;
    return mostTracks;
}

//Insertion sort to arrange a collection alphabetically.
void Collection::sort() {
    int i, j;
    Album *albumKeyP;
    for (i = 1; i < albums.size(); i++) {
        albumKeyP = albums[i];
        j = i - 1;

        while (j >= 0 && *this->albums[j] > *albumKeyP) {
            this->albums[j + 1] = this->albums[j];
            j = j - 1;
        }
        this->albums[j + 1] = albumKeyP;
    }
}

std::ostream &operator<<(std::ostream &Str, const Collection &collection) {
    Str << "Collection: \n";
    for (auto &t : collection.albums) {
        Str << *t << "\n";
    }
    return Str;
}

std::istream &operator>>(std::istream &is, Collection &collectionObj) {
    Album album;
    Album *albumPointer;
    std::vector<Album *> albumVec;
    std::string line;
    while (getline(is, line)) {
        std::istringstream iss(line);
        //Album detected
        if (isalpha(line[0])) {
            iss >> album;
            albumPointer = new Album(album.getArtist(), album.getAlbumTitle());
            albumPointer = collectionObj.addAlbum(albumPointer);
        }
        //Track detected.
        if (isdigit(line[0])) {
            Track track;
            iss >> track;
            albumPointer->addTrack(track);
        }
    }
    return is;
}

void Collection::testHarness() {
    std::cout << "\n=---Collection Test Harness---=" << std::endl;
    Track track = Track("Last Train Home", "00:03:22");
    Track track2 = Track("Uber Everywhere", "00:03:59");
    std::vector<Track> tracks;
    tracks.push_back(track);
    tracks.push_back(track2);
    Album *album = new Album("Zebra", "An Album");
    album->addTrack(track);
    Album *album2 = new Album("Lima", "Also An Album");
    album2->addTrack(track2);
    Collection albumCol = Collection();
    albumCol.addAlbum(album);
    albumCol.addAlbum(album2);
    albumCol.sort();
    std::cout << albumCol << std::endl;
}
