#!/bin/bash

echo "Création du backup..."
sleep 2
cp -r /home/adraqi/* /home/backup/temp/

echo "Compressage du backup..."
sleep 2
date=`date +%Y-%m-%d:%H:%M:%S`
cd /home/backup/
zip -r backup$date.zip temp

echo "Suppression du dossier temporaire"
rm -rf /home/backup/temp/*

echo "Backup termné !"
sleep 4

