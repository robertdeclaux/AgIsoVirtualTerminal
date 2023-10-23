#include "KeyComponent.hpp"
#include "JuceManagedWorkingSetCache.hpp"

KeyComponent::KeyComponent(std::shared_ptr<isobus::VirtualTerminalServerManagedWorkingSet> workingSet, isobus::Key sourceObject) :
  isobus::Key(sourceObject),
  parentWorkingSet(workingSet)
{
	setSize(60, 60);
	setOpaque(true);

	for (std::uint16_t i = 0; i < this->get_number_children(); i++)
	{
		auto child = get_object_by_id(get_child_id(i));

		if (nullptr != child)
		{
			childComponents.push_back(JuceManagedWorkingSetCache::create_component(parentWorkingSet, child));

			if (nullptr != childComponents.back())
			{
				addAndMakeVisible(*childComponents.back());
				childComponents.back()->setTopLeftPosition(get_child_x(i), get_child_y(i));
			}
		}
	}
}

void KeyComponent::paint(Graphics &g)
{
	auto vtColour = colourTable.get_colour(backgroundColor);

	g.fillAll(Colour::fromFloatRGBA(vtColour.r, vtColour.g, vtColour.b, 1.0f));
}