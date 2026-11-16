#ifndef RAFTNODE_H
#define RAFTNODE_H

#include "core/logentry.h"
#include "core/raftmessage.h"
#include "core/simtime.h"

#include <cstdint>
#include <optional>
#include <random>
#include <set>
#include <vector>

enum class Role { Follower, Candidate, Leader };

struct RaftConfig {
    int electionTimeoutMin = 150;
    int electionTimeoutMax = 300;
    int heartbeatInterval = 50;
};

class RaftNode
{
public:
    RaftNode(int id, std::vector<int> peers, RaftConfig config, std::uint32_t seed);

    void start(SimTime now);

    int id() const { return m_id; }
    Role role() const { return m_role; }
    int currentTerm() const { return m_currentTerm; }
    std::optional<int> votedFor() const { return m_votedFor; }
    std::optional<int> leaderId() const { return m_leaderId; }
    SimTime electionDeadline() const { return m_electionDeadline; }
    const std::vector<LogEntry> &log() const { return m_log; }

private:
    void resetElectionTimer(SimTime now);

    int lastLogIndex() const;
    int lastLogTerm() const;
    int termAt(int index) const;

    int m_id;
    std::vector<int> m_peers;
    RaftConfig m_config;

    int m_currentTerm = 0;
    std::optional<int> m_votedFor;
    std::vector<LogEntry> m_log;

    Role m_role = Role::Follower;
    std::optional<int> m_leaderId;
    std::set<int> m_votesReceived;
    SimTime m_electionDeadline = 0;
    SimTime m_nextHeartbeat = 0;
    std::mt19937 m_rng;
    std::vector<RaftMessage> m_outbox;
};

#endif // RAFTNODE_H
