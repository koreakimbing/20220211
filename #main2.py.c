#main2.py
def main():
		...
    client = commands.Bot(command_prefix=prefix, intents = intents, help_command=None)
    ...

    @client.event
    async def on_message(message):  
        if message.author.bot:
            pass
        else:
            name = message.author.name
            channel = message.channel
            await channel.send(f"{name}님이 보내신 메세지를 확인했어요!")

            await client.process_commands(message)

    client.run(token)

if __name__ == '__main__':
    main()