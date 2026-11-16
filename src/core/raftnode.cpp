#include "core/raftnode.h"

#include <utility>

RaftNode::RaftNode(int id, std::vector<int> peers, RaftConfig config, std::uint32_t seed)
    : m_id(id)
    , m_peers(std::move(peers))
    , m_config(config)
    , m_rng(seed)
{}

void RaftNode::start(SimTime now)
{
    m_role = Role::Follower;
    m_leaderId.reset();
    m_votesReceived.clear();
    m_outbox.clear();
    resetElectionTimer(now);
}

void RaftNode::resetElectionTimer(SimTime now)
{
    std::uniform_int_distribution<int> timeout(m_config.electionTimeoutMin,
                                               m_config.electionTimeoutMax);
    m_electionDeadline = now + timeout(m_rng);
}

int RaftNode::lastLogIndex() const
{
    return static_cast<int>(m_log.size());
}

int RaftNode::lastLogTerm() const
{
    return termAt(lastLogIndex());
}

int RaftNode::termAt(int index) const
{
    if (index == 0)
        return 0;
    return m_log[index - 1].term;
}
