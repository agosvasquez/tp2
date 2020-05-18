#include "producer.h"

Producer::Producer(std::map<std::string, int>& material, int& points, BlockingQueue& queue):
 Worker(queue), materials(material),points(points) {}