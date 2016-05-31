# mythplex
Scripts to facility integrating MythTV recording into the Plex Media Server.

Some code (c) 2015 Justin Decker For licensing purposes, use GPLv2

This is a bundle of scripts designed to allow recordings in MythTV to be moved into Plex for later viewing and to give the
option to facilitate long term archival.

These scripts currently require BASH, and haven't been sanitized for other environments. Some configuration is required for
your environment.

### Installing

1. Copy the scripts into a directory that is readable by the MythTV user. (e.g. "/home/mythtv/mythplex/")
2. Modify the file "mythpostprocess.sh" to reflect your configuration.

  At minimum, this entails setting the directories for your TV and Movie folders for your Plex library configuration.

3. In your MythTV setup, create a user job that points to the mythpostprocess.sh script, with the command line arguments of "%CHANID%" "%STARTTIMEUTC%". It should look something like this:


    /home/mythtv/mythplex/mythpostprocess.sh "%CHANID%" "%STARTTIMEUTC%"
