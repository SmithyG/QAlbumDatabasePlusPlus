#include "Utils.h"
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    std::ifstream inFile;
    std::string line;
    std::vector<Track> trackVec;
    std::vector<Album*> albumVec;
    Collection albumCollection;

	QApplication app (argc, argv);
	MainWindow mainWindow;
	mainWindow.show();

    inFile.open("albums.txt");
    if (inFile.fail()){
        std::cout << "Can't read file" << std::endl;
    } else {
        inFile >> albumCollection;
        inFile.close();
    }
    albumCollection.sort();
    std::cout << albumCollection << std::endl;
    std::cout << albumCollection.pinkFloyd() << std::endl;
    std::cout << albumCollection.longestTrack() << std::endl;
    std::cout << albumCollection.mostTracks() << std::endl;

    Duration::testHarness();
    Track::testHarness();
    Album::testHarness();
    Collection::testHarness();

    return app.exec();
}
