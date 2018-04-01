﻿/*
 * (c) Copyright Ascensio System SIA 2010-2018
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once
#ifndef PPTX_LOGIC_BLDOLECHART_INCLUDE_H_
#define PPTX_LOGIC_BLDOLECHART_INCLUDE_H_

#include "./../../WrapperWritingElement.h"
#include "./../../Limit/ChartBuildType.h"

namespace PPTX
{
	namespace Logic
	{
		class BldOleChart : public WrapperWritingElement
		{
		public:
			PPTX_LOGIC_BASE(BldOleChart)

		public:
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				spid		= node.GetAttribute(_T("spid"));
				grpId		= node.ReadAttributeInt(L"grpId");
				node.ReadAttributeBase(L"uiExpand", uiExpand);
				node.ReadAttributeBase(L"bld", bld);
				node.ReadAttributeBase(L"animBg", animBg);

				Normalize();

				FillParentPointersForChilds();
			}

			virtual std::wstring toXML() const
			{
				XmlUtils::CAttribute oAttr;
				oAttr.Write(_T("spid"), spid);
				oAttr.Write(_T("grpId"), grpId);
				oAttr.Write(_T("uiExpand"), uiExpand);
				oAttr.WriteLimitNullable(_T("bld"), bld);
				oAttr.Write(_T("animBg"), animBg);

				return XmlUtils::CreateNode(_T("p:bldOleChart"), oAttr);
			}

		public:
			std::wstring									spid;
			int										grpId;
			nullable_bool							uiExpand;
			nullable_limit<Limit::ChartBuildType>	bld;
			nullable_bool							animBg;
		protected:
			virtual void FillParentPointersForChilds(){};

			AVSINLINE void Normalize()
			{
				if (grpId < 0)
					grpId = 0;
			}
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_BLDOLECHART_INCLUDE_H