#include <utility>

template <typename ResourceType, typename Deleter = void(ResourceType)> class Resource
{
  public:
    Resource(ResourceType &&resource, Deleter &deleter)
        : resource(std::forward<ResourceType>(resource)), deleter(deleter)
    {
    }

    ~Resource()
    {
        deleter(resource);
    }

    ResourceType resource;

  private:
    Deleter &deleter;
};
