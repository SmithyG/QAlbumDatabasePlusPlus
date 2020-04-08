//
// Created by smith on 05/04/2019.
//

#ifndef CW2_COLLECTION_H
#define CW2_COLLECTION_H

#include <ostream>
#include "Utils.h"
#include "Album.h"

class Collection {

public:
    static void testHarness();

    Collection();

    explicit Collection(std::vector<Album*> albums);

    Album* addAlbum(Album* albPointer);

    const std::vector<Album*> &getAlbums() const;

    friend std::ostream &operator<<(std::ostream &Str, const Collection &collection);

    friend std::istream &operator>>(std::istream &is, Collection &collectionObj);

    Duration pinkFloyd();

    Track longestTrack();

    Album mostTracks();

    void sort();

private:
    std::vector<Album*> albums;
};


#endif //CW2_COLLECTION_H
