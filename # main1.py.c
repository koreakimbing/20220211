# main1.py
import discord
from discord.ext import commands
import os

def main():
		...
		client = commands.Bot(command_prefix=prefix, intents = intents)

    for filename in os.listdir('./cogs'):
        if '.py' in filename:
            filename = filename.replace('.py', '')
            client.load_extension(f"cogs.{filename}")
		...
    client.run(token)

if __name__ == '__main__':
    main()