#main.py
def main():
		...
    client = commands.Bot(command_prefix=prefix, intents = intents, help_command=None)
    ...
		@client.command(name = "추가")
    async def _load(ctx, extension):
        client.load_extension(f'cogs.{extension}')
        await ctx.send(f"{extension}이 추가 되었어요!")

    @client.command(name = "제거")
    async def _unload(ctx, extension):
        client.unload_extension(f"cogs.{extension}")
        await ctx.send(f"{extension}이 제거 되었어요!")

    @client.command(name = "새로고침")
    async def _reload(ctx, extension):
        client.unload_extension(f"cogs.{extension}")
        client.load_extension(f'cogs.{extension}')
        await ctx.send(f"{extension}이 새로고침 되었어요!")
    client.run(token)

if __name__ == '__main__':
    main()