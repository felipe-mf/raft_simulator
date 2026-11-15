#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <QString>

struct LogEntry {
    int term = 0;
    QString command;
};

#endif // LOGENTRY_H
