#pragma once

#include <folly/MPMCQueue.h>
#include <memory>
#include <string>
#include <thread>

namespace work {

using taskType = std::function<void()>;

class WorkerThread {
  std::unique_ptr<std::thread> thread;
  folly::MPMCQueue<std::unique_ptr<taskType>> tasks;
  const std::string name;

public:
  WorkerThread(const std::string name);
  void scheduleTask(const taskType task);
  ~WorkerThread();
};

} // namespace work
