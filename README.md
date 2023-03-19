# Nikki (日記)

Nikki is a simple program that I've made to organise my life based on plain text
files. I'm making it public because it may also be useful to someone else who
likes to keep things simple.

It has two components, both with .nk extension: your schedule, and your daily
files.

Your schedule file (schedule.nk) has events with tasks defined as follows:

```nikki
__Name of the event
  # Mon Thu Sat
  15:00 to 15:30
  - task 1
  - task 2

__Event 2 $red
  # Tue
  12:00 to 13:00
  - task 3

```

Some guidelines:
- An event can have no tasks. 
- The file always ends with an empty line.
- Events are separated by an empty line.
- The line starting with # can have any combination of days of the week.
- Events can have colours that can be displayed by the show.cpp program, which shows the events of the day with all tasks marked as TODO.
- It accepts terminal colours (red, green, yellow, blue, purple, cyan);

The program generates the daily file named YYYY-MM-DD.nk with the following content:

Considering today is Tuesday:

```nikki
__Event 2 $red
  12:00 to 13:00
  TODO task 3

```

The way I use this daily file is to have a shortcut inside Neovim that changes
tasks from TODO to DONE. I use Neovim to mark my tasks as done, and the show
program whenever I just want to see what tasks are left.

The file also supports trackers that are defined in constants.h, these are habits
that you want to track, if that is not something you want, just leave the vector
empty.