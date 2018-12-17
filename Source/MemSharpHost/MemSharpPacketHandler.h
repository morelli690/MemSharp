#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace Ether::Network::Server;
using namespace Ether::Network::Packets;

ref class MemSharpPacketHandler
{
public:
	enum class OpCode
	{
		Shutdown,
		SetWorkingDirectory
	};

public:
	static MemSharpPacketHandler();

	static Action<INetPacketStream^>^ GetHandler(OpCode opCode);
public:
	
	static Dictionary<OpCode, Action<INetPacketStream^>^>^ PacketHandlers = gcnew Dictionary<OpCode, Action<INetPacketStream^>^>();
};
