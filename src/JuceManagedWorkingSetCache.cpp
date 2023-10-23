#include "JuceManagedWorkingSetCache.hpp"

#include "AlarmMaskComponent.hpp"
#include "ButtonComponent.hpp"
#include "ColourMapComponent.hpp"
#include "ContainerComponent.hpp"
#include "DataMaskComponent.hpp"
#include "ExtendedInputAttributesComponent.hpp"
#include "FillAttributesComponent.hpp"
#include "InputBooleanComponent.hpp"
#include "InputListComponent.hpp"
#include "InputNumberComponent.hpp"
#include "InputStringComponent.hpp"
#include "KeyComponent.hpp"
#include "KeyGroupComponent.hpp"
#include "LineAttributesComponent.hpp"
#include "MacroComponent.hpp"
#include "NumberVariableComponent.hpp"
#include "ObjectPointerComponent.hpp"
#include "OutputArchedBarGraphComponent.hpp"
#include "OutputEllipseComponent.hpp"
#include "OutputLineComponent.hpp"
#include "OutputLinearBarGraphComponent.hpp"
#include "OutputListComponent.hpp"
#include "OutputMeterComponent.hpp"
#include "OutputNumberComponent.hpp"
#include "OutputPolygonComponent.hpp"
#include "OutputRectangleComponent.hpp"
#include "OutputStringComponent.hpp"
#include "PictureGraphicComponent.hpp"
#include "SoftKeyMaskComponent.hpp"
#include "StringVariableComponent.hpp"
#include "WorkingSetComponent.hpp"

std::vector<JuceManagedWorkingSetCache::ComponentCacheClass> JuceManagedWorkingSetCache::workingSetComponentCache;

std::shared_ptr<Component> JuceManagedWorkingSetCache::create_component(std::shared_ptr<isobus::VirtualTerminalServerManagedWorkingSet> workingSet, std::shared_ptr<isobus::VTObject> sourceObject)
{
	std::shared_ptr<Component> retVal;
	bool isWorkingSetKnown = false;

	for (auto &knownWorkingSet : workingSetComponentCache)
	{
		if (knownWorkingSet.workingSet == workingSet)
		{
			isWorkingSetKnown = true;
			break;
		}
	}

	if (!isWorkingSetKnown)
	{
		workingSetComponentCache.emplace_back(workingSet);
	}

	if (nullptr != sourceObject)
	{
		switch (sourceObject->get_object_type())
		{
			case isobus::VirtualTerminalObjectType::AlarmMask:
			{
				retVal = std::make_shared<AlarmMaskComponent>(workingSet, *std::static_pointer_cast<isobus::AlarmMask>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::DataMask:
			{
				retVal = std::make_shared<DataMaskComponent>(workingSet, *std::static_pointer_cast<isobus::DataMask>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::Container:
			{
				retVal = std::make_shared<ContainerComponent>(workingSet, *std::static_pointer_cast<isobus::Container>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::WindowMask:
			{
			}
			break;

			case isobus::VirtualTerminalObjectType::SoftKeyMask:
			{
				retVal = std::make_shared<SoftKeyMaskComponent>(workingSet, *std::static_pointer_cast<isobus::SoftKeyMask>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::Key:
			{
				retVal = std::make_shared<KeyComponent>(workingSet, *std::static_pointer_cast<isobus::Key>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::Button:
			{
				retVal = std::make_shared<ButtonComponent>(workingSet, *std::static_pointer_cast<isobus::Button>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::KeyGroup:
			case isobus::VirtualTerminalObjectType::InputBoolean:
			case isobus::VirtualTerminalObjectType::InputString:
			{
			}
			break;

			case isobus::VirtualTerminalObjectType::InputNumber:
			{
				retVal = std::make_shared<InputNumberComponent>(workingSet, *std::static_pointer_cast<isobus::InputNumber>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::InputList:
			{
				retVal = std::make_shared<InputListComponent>(workingSet, *std::static_pointer_cast<isobus::InputList>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputString:
			{
				retVal = std::make_shared<OutputStringComponent>(workingSet, *std::static_pointer_cast<isobus::OutputString>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputNumber:
			{
				retVal = std::make_shared<OutputNumberComponent>(workingSet, *std::static_pointer_cast<isobus::OutputNumber>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputList:
			{
				//retVal = std::make_shared<OutputListComponent>(workingSet, *std::static_pointer_cast<isobus::OutputList>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputLine:
			{
				retVal = std::make_shared<OutputLineComponent>(workingSet, *std::static_pointer_cast<isobus::OutputLine>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputRectangle:
			{
				retVal = std::make_shared<OutputRectangleComponent>(workingSet, *std::static_pointer_cast<isobus::OutputRectangle>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputEllipse:
			{
				retVal = std::make_shared<OutputEllipseComponent>(workingSet, *std::static_pointer_cast<isobus::OutputEllipse>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputPolygon:
			{
				retVal = std::make_shared<OutputPolygonComponent>(workingSet, *std::static_pointer_cast<isobus::OutputPolygon>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputMeter:
			{
				retVal = std::make_shared<OutputMeterComponent>(workingSet, *std::static_pointer_cast<isobus::OutputMeter>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputLinearBarGraph:
			{
				retVal = std::make_shared<OutputLinearBarGraphComponent>(workingSet, *std::static_pointer_cast<isobus::OutputLinearBarGraph>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::OutputArchedBarGraph:
			case isobus::VirtualTerminalObjectType::GraphicsContext:
			case isobus::VirtualTerminalObjectType::Animation:
			{
			}
			break;

			case isobus::VirtualTerminalObjectType::PictureGraphic:
			{
				retVal = std::make_shared<PictureGraphicComponent>(workingSet, *std::static_pointer_cast<isobus::PictureGraphic>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::NumberVariable:
			case isobus::VirtualTerminalObjectType::StringVariable:
			case isobus::VirtualTerminalObjectType::FontAttributes:
			case isobus::VirtualTerminalObjectType::LineAttributes:
			case isobus::VirtualTerminalObjectType::FillAttributes:
			case isobus::VirtualTerminalObjectType::InputAttributes:
			case isobus::VirtualTerminalObjectType::ExtendedInputAttributes:
			case isobus::VirtualTerminalObjectType::ColourMap:
			case isobus::VirtualTerminalObjectType::ObjectLabelRefrenceList:
			{
			}
			break;

			case isobus::VirtualTerminalObjectType::ObjectPointer:
			{
				retVal = std::make_shared<ObjectPointerComponent>(workingSet, *std::static_pointer_cast<isobus::ObjectPointer>(sourceObject));
			}
			break;

			case isobus::VirtualTerminalObjectType::ExternalObjectDefinition:
			case isobus::VirtualTerminalObjectType::ExternalReferenceNAME:
			case isobus::VirtualTerminalObjectType::ExternalObjectPointer:
			case isobus::VirtualTerminalObjectType::Macro:
			case isobus::VirtualTerminalObjectType::AuxiliaryFunctionType1:
			case isobus::VirtualTerminalObjectType::AuxiliaryInputType1:
			case isobus::VirtualTerminalObjectType::AuxiliaryFunctionType2:
			case isobus::VirtualTerminalObjectType::AuxiliaryInputType2:
			case isobus::VirtualTerminalObjectType::AuxiliaryControlDesignatorType2:
			{
			}
			break;
		}
	}
	return retVal;
}