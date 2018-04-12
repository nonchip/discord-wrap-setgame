#!/bin/bash
TF="/tmp/discord-setgame.$1"
shift 1
cp "$(dirname "$(readlink -f "$0")")/build/discord-setgame" "$TF"
"$@" &
"$TF" $!
