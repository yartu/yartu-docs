﻿/*
 * (c) Copyright Ascensio System SIA 2010-2015
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
 function getTestWorkbook() {
    return "XLSY;v2;5548;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";
}