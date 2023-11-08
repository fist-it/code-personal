import discord
from discord.ext import commands
import random
import json

bot = commands.Bot(command_prefix='.', intents=discord.Intents.all())

@bot.event
async def on_ready():
    print('Logged on!!')
    try:
        synced = await bot.tree.sync()
        print(f"synced {len(synced)} command(s)")
    except Exception as e:
        print(e)
        
@bot.tree.command(name="hello")
async def hello(interaction: discord.Interaction):
    await interaction.response.send_message(f"Heja {interaction.user.mention}! to ten /")
@bot.tree.command(name="next")
async def next(interaction: discord.Interaction):
    next = ['nuke', 'inferno', 'pass', 'pass']
    await interaction.response.send_message(random.choice(next))
@bot.tree.command(name="map")
async def map(interaction: discord.Interaction):
    maps = ["nuke", "inferno"]
    await interaction.response.send_message(random.choice(maps))


@bot.event
async def on_message(message):
    if message.content.startswith('hola'):
        await message.channel.send('hola!')
    
    






with open('config.json', 'r') as file:
    data = json.load(file)
bot.run(data["TOKEN"])