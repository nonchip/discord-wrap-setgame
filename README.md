# Installing

    mkdir build
    cd build
    cmake ..
    make
    cd ..
    sudo ln -s $PWD/discord-wrap-setgame.sh /usr/local/bin/discord-setgame

# Usage

Simply prefix the command line of your game with `discord-setgame GAMENAME`.

Then go to the `discord settings -> Games -> Add it!`, select `discord-setgame.GAMENAME` from the dropdown, and give it a nice name.

# Why?

primarily since discord can't distinguish multiple different games running in WINE from each other, since it seems to use `readlink(/proc/*/exe)` to get the game's executable instead of it's actual process name (which WINE would set to the game's exe file name), so it only ever sees "you are running wine".
