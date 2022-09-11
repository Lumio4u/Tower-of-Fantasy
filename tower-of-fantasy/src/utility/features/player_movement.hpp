#pragma once
#include "../unreal_engine_utility.hpp"
#include "script.hpp"

namespace big::movement
{
	inline void no_clip(bool activate)
	{
		if (auto player = unreal_engine::get_local_player())
		{
			if (activate)
			{
				player->m_player_controller->m_acknowledge_pawn->no_clip = 0x40;
			}
			else
			{
				player->m_player_controller->m_acknowledge_pawn->no_clip = 0x44;
			}
		}
	}

	inline void infinite_dodge(bool activate)
	{
		if (activate)
		{
			if (GetAsyncKeyState(VK_LSHIFT) & 0x1)
			{
				if (auto player = unreal_engine::get_local_player())
				{
					if (auto controller = player->m_player_controller)
					{
						if (auto pawn = controller->m_pawn)
						{
							pawn->m_rand_bean = 6001;
							pawn->m_cur_bean_count = 6641;
							pawn->m_change_time = 637963816908830000;
							if (auto self = unreal_engine::get_hotta_character(); self)
							{
								self->update_evade_count();
							}
						}
					}
				}
			}
		}
	}

	inline Vector3* get_entity_coords()
	{
		if (auto pawn = unreal_engine::get_pawn())
		{
			if (auto self = pawn->m_capsule_component)
			{
				return &self->m_position;
			}
		}

		return nullptr;
	}

	inline void set_entity_coords(Vector3 coords)
	{
		TRY_CLAUSE
		{
			if (auto self = unreal_engine::get_hotta_character(); self)
			{
				self->server_teleport_to(coords, Rotator(0.f, 0.f, 0.f));
			}
		} EXCEPT_CLAUSE
	}

	inline float* player_movement_speed()
	{
		if (auto player = unreal_engine::get_local_player())
			return &player->m_player_controller->m_pawn->m_chara_movement->m_movement_speed;

		return nullptr;
	}

	inline float* player_crouch_speed()
	{
		if (auto player = unreal_engine::get_local_player())
			return &player->m_player_controller->m_pawn->m_chara_movement->m_crouch_speed;

		return nullptr;
	}

	inline float* player_swim_speed()
	{
		if (auto player = unreal_engine::get_local_player())
			return &player->m_player_controller->m_pawn->m_max_swim_speed;

		return nullptr;
	}

	inline float* player_fly_speed()
	{
		if (auto player = unreal_engine::get_local_player())
			return &player->m_player_controller->m_pawn->m_chara_movement->m_fly_speed;

		return nullptr;
	}

	inline float* player_gravity()
	{
		if (auto player = unreal_engine::get_local_player())
			return &player->m_player_controller->m_pawn->m_gravity;

		return nullptr;
	}

	inline void infinite_jump(bool activate)
	{
		if (activate)
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x1)
			{
				if (auto player = unreal_engine::get_local_player())
				{
					if (auto controller = player->m_player_controller)
					{
						if (auto actor_pawn = controller->m_pawn)
						{
							actor_pawn->m_jump_count = 0;
						}
					}
				}
			}
		}
	}

	inline bool is_crouch()
	{
		if (auto player = unreal_engine::get_local_player())
			return player->m_player_controller->m_pawn->m_is_crouch;

		return false;
	}

	inline bool is_armor_broken()
	{
		if (auto player = unreal_engine::get_local_player())
			return player->m_player_controller->m_pawn->m_is_armor_break;

		return false;
	}

	inline float* game_speed()
	{
		if (auto player = unreal_engine::get_local_player())
		{
			return &player->m_player_controller->m_pawn->m_game_speed;
		}

		return nullptr;
	}

	inline void freeze_mobs(bool activate)
	{
		if (auto player = unreal_engine::get_local_player())
		{
			uint8_t freeze_status = player->m_player_controller->m_pawn->m_freeze_mobs;
			if (activate && !freeze_status)
			{
				player->m_player_controller->m_pawn->m_freeze_mobs = true;
			}
			else if (activate && freeze_status)
			{
				player->m_player_controller->m_pawn->m_freeze_mobs = false;
			}
		}
	}

	inline void freeze_entity(bool activate)
	{
		if (auto player = unreal_engine::get_local_player())
		{
			if (activate)
			{
				player->m_player_controller->m_pawn->m_chara_movement->m_freeze_entity = false;
			}
			else
			{
				player->m_player_controller->m_pawn->m_chara_movement->m_freeze_entity = true;
			}
		}
	}
}