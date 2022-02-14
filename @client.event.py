@client1.event
async def on_message(message):  
    name = message.author.name
    channel = message.channel
    await channel.send(f"{name}님이 보내신 메세지를 확인했어요!")

    await client.process_commands(message)