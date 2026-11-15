#ifndef RAFTMESSAGE_H
#define RAFTMESSAGE_H

#include "core/logentry.h"

#include <vector>

struct RaftMessage {
    // enum class para evitar o vazamento dos nomes no restante do projeto (outros lugares precisam declarar nome completo)
    // exemplo: msg.type = RaftMessage::Type::RequestVote

    enum class Type { RequestVote, RequestVoteReply, AppendEntries, AppendEntriesReply };

    Type type = Type::RequestVote;
    int from = -1;
    int to   = -1;
    int term = 0;

    int lastLogIndex = 0;
    int lastLogTerm  = 0;

    bool voteGranted = false;

    int prevLogIndex = 0;
    int prevLogTerm  = 0;
    std::vector<LogEntry> entries;
    int leaderCommit = 0;

    bool success    = false;
    int  matchIndex = 0;
};

#endif // RAFTMESSAGE_H
