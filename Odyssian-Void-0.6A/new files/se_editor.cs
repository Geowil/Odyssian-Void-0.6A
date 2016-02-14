using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ov_mod_tool
{
    public partial class se_editor : Form
    {
        bool bMSelected;
        bool bDTSelected;
        int i1, i2, i3, i4, i5;

        string sIDS; //Ship IDS - imported
        string wIDS; //Weapon IDS - imported
        string mIDS; //Mining Laser IDS - imported
        string cNames; //Class Names - imported
        string wnames; //Weapon Names - imported
        string lbName; //Hold unmodified label name
        int scTypes;
        string[] scNames, pTitles, wNames, mlList;
        List<string> sCIDS;
        List<string> wCIDS;
        List<string> mCIDS;
        string[] temp, temp2;
        List<string> temp3, temp4;
        string data; //Hold imported data for further processing

        bool bCanDelete;

        iniFile iF_S;

        GroupBox gBox1, gBox2, gBox3;
        Label label1, label2, lb_SESC_C;
        TextBox tBox1, tBox2, tb_SESC_C;
        List<Control> gBoxes, gBoxes2, gBoxes3;
        List<Control> labels, labels2;
        List<Control> tBoxes, tBoxes2;

        int curXPos;
        int curYPos;

        //Const vals for sEditor Ship Class Type Editing
        const int gbX_S_SESC = 30; //For Group Boxes - SE Ship IDs
        const int gbX_S_SESC2 = 16; //For Group Boxes - SE Weapon Sections
        const int gbX_S_SESC3 = 6; //For Group Boxes - SE Weapon IDs
        const int gbX_S_SESC4 = 58;
        const int gbX_S_SESC5 = 173;
        const int gbX_S_SESC6 = 6;
        const int gbY_S_SESC = 53; //For Group Boxes - SE Ship IDs
        const int gbY_S_SESC2 = 59; //For Group Boxes - SE Weapon Sections
        const int gbY_S_SESC3 = 19; //For Group Boxes - SE Weapon IDs
        const int gbY_S_SESC4 = 68;
        const int gbY_S_SESC5 = 245;
        const int gbY_S_SESC6 = 19;
        const int gbH_SESC = 71; //For Group Boxes - SE Ship IDs
        const int gbH_SESC2 = 199; //For Group Boxes - SE Weapon Sections
        const int gbH_SESC3 = 171;
        const int gbH_SESC4 = 97;
        const int gbW_SESC = 120; //For Group Boxes - SE Ship IDs
        const int gbW_SESC2 = 584; //For Group Boxes - SE Weapon Sections        
        const int gbW_SESC3 = 539;
        const int gbW_SESC4 = 263;

        const int tbH_SESC = 20;
        const int tbW_SESC = 52;
        const int tbLX_SESC = 55;
        const int tbLY_SESC = 22;
        const int tbHX_SESC = 55;
        const int tbHY_SESC = 45;

        const int lbH_SESC = 20;
        const int lbLW_SESC = 41;
        const int lbHW_SESC = 43;
        const int lbLX_SESC = 6;
        const int lbLY_SESC = 22;
        const int lbHX_SESC = 6;
        const int lbHY_SESC = 45;

        const int mX = 150; //For Singlular
        const int mX2 = 126;
        const int mY = 91; //For Singular
        const int mY2 = 205; //For Singular - Weapon Group Boxes
        const int mY3 = 54; //For Compact
        const int mY4 = 77;

        const int tbH_SESC_C = 20;
        const int tbW_SESC_C = 535;
        const int tbX_SESC_C = 32;
        const int tbY_SESC_C = 85;
        const int lbH_SESC_C = 13;
        const int lbW_SESC_C = 250;
        const int lbX_SESC_C = 20;
        const int lbY_SESC_C = 69;

        public se_editor()
        {
            InitializeComponent();

            bMSelected = false;
            bDTSelected = false;
            toolStrip1.Renderer = new myRenderer(); // Just add this line to public



            this.gBoxes = new List<Control>();
            this.gBoxes2 = new List<Control>();
            this.gBoxes3 = new List<Control>();
            this.labels = new List<Control>();
            this.labels2 = new List<Control>();
            this.tBoxes = new List<Control>();
            this.tBoxes2 = new List<Control>();
            this.sCIDS = new List<string>();
            this.wCIDS = new List<string>();
            this.mCIDS = new List<string>();
            this.temp3 = new List<string>();
            this.temp4 = new List<string>();
        }

        private void m_DT_MLasers_Click(object sender, EventArgs e)
        {
            sCheck(2, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_MLasers.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_MLasers.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_Ships_Click(object sender, EventArgs e)
        {
            sCheck(5, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_Ships.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_Ships.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_SShip_Click(object sender, EventArgs e)
        {
            sCheck(6, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_SShips.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_SShips.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_Weaps_Click(object sender, EventArgs e)
        {
            sCheck(7, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_Weaps.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_Weaps.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_M_Compact_Click(object sender, EventArgs e)
        {
            sCheck(0, m_Mode.DropDownItems);

            if ((bMSelected) && (!m_M_Compact.Checked))
            {
                bMSelected = false;
            }

            else if ((!bMSelected) && (m_M_Compact.Checked))
            {
                bMSelected = true;
            }
        }

        private void m_M_Singular_Click(object sender, EventArgs e)
        {
            sCheck(1, m_Mode.DropDownItems);

            if ((bMSelected) && (!m_M_Singular.Checked))
            {
                bMSelected = false;
            }

            else if ((!bMSelected) && (m_M_Singular.Checked))
            {
                bMSelected = true;
            }
        }

        private void sCheck(int iSkip, ToolStripItemCollection mic)
        {
            i1 = 0;
            foreach (ToolStripMenuItem mi in mic)
            {
                if (i1 != iSkip)
                {
                    mi.Checked = false;
                }

                i1 += 1;
            }
        }

        private void bCheck()
        {
            if ((bMSelected) && (bDTSelected))
            {
                m_LData.Enabled = true;
            }

            else
            {
                m_LData.Enabled = false;
            }
        }

        private string lData(string kname, string dlocal)
        {
            try
            {
                //utf8Bytes = Encoding.UTF8.GetBytes(gVars.ovs_local);
                //path = Encoding.Unicode.GetString(utf8Bytes);
                iF_S = new iniFile(gVars.ovs_local);

                return iF_S.Read(kname, dlocal);

                //MessageBox.Show(null, sClasses, "Test", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);                    
            }

            catch (NullReferenceException err)
            {
                MessageBox.Show(null, err.ToString(), "No File Loaded", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return "";
            }

            catch (FileNotFoundException err)
            {
                MessageBox.Show(null, err.ToString(), "File Not Found", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return "";
            }
        }

        private void m_H_Tuts_Click(object sender, EventArgs e)
        {
            string url = "http://stackoverflow.com/";
            System.Diagnostics.Process.Start(url);
        }

        private void m_DT_MLasers_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void m_DT_Ships_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void m_DT_SShips_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void m_DT_Weaps_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void m_M_Compact_CheckedChanged(object sender, EventArgs e)
        {
            if ((bMSelected) && (!m_M_Compact.Checked))
            {
                bMSelected = false;
            }

            else if ((!bMSelected) && (m_M_Compact.Checked))
            {
                bMSelected = true;
            }

            bCheck();
        }

        private void m_M_Singular_CheckedChanged(object sender, EventArgs e)
        {
            if ((bMSelected) && (!m_M_Singular.Checked))
            {
                bMSelected = false;
            }

            else if ((!bMSelected) && (m_M_Singular.Checked))
            {
                bMSelected = true;
            }

            bCheck();
        }

        private void m_LData_Click(object sender, EventArgs e)
        {
            if (m_M_Compact.Checked)
            {
                if (m_DT_MLasers.Checked)
                {
                    mIDS = lData("mlidrstr", "itemid");
                    cNames = lData("scnames", "sclasses");
                }

                else if (m_DT_Ships.Checked)
                {
                    sIDS = lData("sidrstr", "itemid");
                    cNames = lData("scnames", "sclasses");

                    sCIDS.Add(sIDS);

                    pTitles = new string[1];

                    pTitles[0] = m_DT_Ships.Text;

                    cControls(pTitles.Count(), pTitles, sCIDS, "sids", "compact");

                }

                else if (m_DT_SShips.Checked)
                {
                    sIDS = lData("ssrstr", "itemid");
                    cNames = "S. Ship ID Range";

                    sCIDS.Add(sIDS);

                    pTitles = new string[1];

                    pTitles[0] = cNames;

                    cControls(pTitles.Count(), pTitles, sCIDS, "ssids", "compact");
                }

                else if (m_DT_Weaps.Checked)
                {                   
                    wIDS = lData("widrstr", "itemid");
                    wnames = lData("wcnames", "wclasses");

                    wNames = wnames.Split(',');

                    for (i1 = 0; i1 < wNames.Count(); i1++)
                    {
                        wNames[i1] = upperFChar(wNames[i1]);
                        wNames[i1] = wNames[i1] + " Weapon ID List";
                    }

                    temp = wIDS.Split(';');

                    foreach (string s in temp)
                    {
                        wCIDS.Add(s);
                    }

                    cControls(wNames.Count(), wNames, wCIDS, "wids", "compact");
                }
            }

            else if (m_M_Singular.Checked)
            {
                if (m_DT_MLasers.Checked)
                {
                    mIDS = lData("mlidrstr", "itemid");
                    cNames = lData("scnames", "sclasses");

                    temp = mIDS.Split(';');

                    foreach (string el in temp)
                    {
                        temp2 = el.Split(',');

                        foreach (string el2 in temp2)
                        {
                            temp3.Add(el2);
                        }
                    }

                    foreach (string el3 in temp3)
                    {
                        temp = el3.Split('-');

                        foreach (string el4 in temp)
                        {
                            mCIDS.Add(el4);
                        }
                    }

                    scNames = cNames.Split(',');

                    //Code to deal with mining barge bug
                    scNames = Array.FindAll(scNames, isNMBarge).ToArray();

                    i1 = 0;

                    foreach (string el in scNames)
                    {
                        scNames[i1] = el.Replace('_', ' ');
                        i1++;
                    }

                    cControls(scNames.Count(), scNames, mCIDS, "mids", "singular");
                }

                else if (m_DT_Ships.Checked)
                {
                    sIDS = lData("sidrstr", "itemid");
                    cNames = lData("scnames", "sclasses");

                    //MessageBox.Show(null, "It Worked!", "Testing CBox Index Select", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);

                    //Split the class names and place them into a arraylist
                    scNames = cNames.Split(',');

                    for (i1 = 0; i1 < scNames.Count(); i1++)
                    {
                        scNames[i1] = scNames[i1].Replace('_', ' ');
                    }

                    //Split the class IDs by hyphens and commas and then insert into sCIDS
                    temp = sIDS.Split(',');

                    foreach (string s in temp)
                    {
                        temp2 = s.Split('-');

                        sCIDS.Add(temp2.ElementAt(0));
                        sCIDS.Add(temp2.ElementAt(1));
                    }

                    //scNames[0] = "Test";

                    cControls(scNames.Count(), scNames, sCIDS, "sids", "singular");

                    //addLabels(1,scNames);
                }

                else if (m_DT_SShips.Checked)
                {
                    sIDS = lData("ssrstr", "itemid");
                    cNames = "S. Ship ID Range";


                    temp = sIDS.Split('-');

                    sCIDS.Add(temp.ElementAt(0));
                    sCIDS.Add(temp.ElementAt(1));

                    pTitles = new string[1];
                    pTitles[0] = cNames;

                    cControls(pTitles.Count(), pTitles, sCIDS, "ssids", "singular");
                }

                else if (m_DT_Weaps.Checked)
                {
                    wIDS = lData("widrstr", "itemid");
                    cNames = lData("scnames", "sclasses");
                    scTypes = Int32.Parse(lData("sctypes", "sclasses"));

                    scTypes -= 1;

                    temp = wIDS.Split(';');

                    foreach (string el in temp)
                    {
                        temp2 = el.Split(',');

                        foreach (string el2 in temp2)
                        {
                            temp3.Add(el2);
                        }
                    }

                    foreach (string el3 in temp3)
                    {
                        temp = el3.Split('-');

                        foreach (string el4 in temp)
                        {
                            wCIDS.Add(el4);
                        }
                    }

                    scNames = cNames.Split(',');

                    //Code to deal with mining barge bug
                    scNames = Array.FindAll(scNames, isNMBarge).ToArray();

                    i1 = 0;

                    foreach (string el in scNames)
                    {
                        scNames[i1] = el.Replace('_', ' ');
                        i1 += 1;
                    }

                    //Get weapon names
                    wnames = lData("wcnames", "wclasses");

                    wNames = wnames.Split(',');

                    for (i1 = 0; i1 < wNames.Count(); i1++)
                    {
                        wNames[i1] = upperFChar(wNames[i1]);
                        wNames[i1] = wNames[i1] + " Weapon ID List";
                    }

                    cControls(scNames.Count(), scNames, wCIDS, "wids", "singular");

                }
            }
        }

        private void cControls(int i, string[] sList, List<string> idList, string flag, string flag2)
        {
            //Reset to zero here for use later in the for loop below
            i2 = 0;
            i3 = 0;
            i5 = 0;

            if (flag == "sids" || flag == "ssids")
            {
                if (flag2 == "singular")
                {
                    for (i1 = 0; i1 < i; i1++)
                    {
                        gBox1 = new GroupBox();
                        gBox1.Text = sList[i1];

                        if (gbX_S_SESC + (mX * i2) > 482) //IF the value of X has reached 429, move down to a new row
                        {
                            i3 += 1;
                            i2 = 0;
                            gBox1.Location = new Point(gbX_S_SESC, gbY_S_SESC + (mY * i3));
                            i2 += 1;
                        }

                        else //Else if the value of X is less than or equal to 482
                        {
                            gBox1.Location = new Point(gbX_S_SESC + (mX * i2), gbY_S_SESC + (mY * i3));
                            i2 += 1;
                        }


                        gBox1.Height = gbH_SESC;
                        gBox1.Width = gbW_SESC;

                        label1 = new Label();
                        label2 = new Label();
                        tBox1 = new TextBox();
                        tBox2 = new TextBox();

                        label1.Text = "Low ID";
                        label2.Text = "High ID";

                        tBox1.Text = idList.ElementAt(i5);
                        tBox2.Text = idList.ElementAt(i5 + 1);

                        i5 += 2;

                        label1.Location = new Point(lbLX_SESC, lbLY_SESC);
                        label2.Location = new Point(lbHX_SESC, lbHY_SESC);
                        tBox1.Location = new Point(tbLX_SESC, tbLY_SESC);
                        tBox2.Location = new Point(tbHX_SESC, tbHY_SESC);

                        label1.Size = new System.Drawing.Size(lbLW_SESC, lbH_SESC);
                        label2.Size = new System.Drawing.Size(lbHW_SESC, lbH_SESC);

                        tBox1.Size = new System.Drawing.Size(tbW_SESC, tbH_SESC);
                        tBox2.Size = new System.Drawing.Size((tbW_SESC), tbH_SESC);

                        addControl(gBoxes, gBox1);
                        addControl(labels, label1);
                        addControl(labels, label2);
                        addControl(tBoxes, tBox1);
                        addControl(tBoxes, tBox2);
                    }

                    //Once all of the elements have been made, add them to the proper controls and show them
                    rControls("singular", "mode1");
                }

                else if (flag2 == "compact")
                {
                    for (i1 = 0; i1 < i; i1++)
                    {
                        label1 = new Label();
                        label1.Text = sList[i1];

                        label1.Location = new Point(lbX_SESC_C, lbY_SESC_C + (mY3 * i1));

                        label1.Size = new System.Drawing.Size(lbW_SESC_C, lbH_SESC_C);

                        tBox1 = new TextBox();
                        tBox1.Text = idList.ElementAt(i1);

                        tBox1.Location = new Point(tbX_SESC_C, tbY_SESC_C + (mY3 * i1));

                        tBox1.Size = new System.Drawing.Size(tbW_SESC_C, tbH_SESC_C);

                        addControl(labels2, label1);
                        addControl(tBoxes2, tBox1);
                    }

                    rControls("compact", "mode1");
                }
            }

            else if (flag == "wids")
            {
                if (flag2 == "singular")
                {
                    i3 = 0;
                    i4 = 0;
                    i5 = 0;

                    for (i1 = 0; i1 < wNames.Count(); i1++)
                    {
                        gBox1 = new GroupBox();
                        gBox1.Text = wNames.ElementAt(i1);

                        gBox1.Location = new Point(16, 59 + (mY2 * i1));
                        gBox1.Size = new System.Drawing.Size(gbW_SESC2, gbH_SESC2);

                        gBoxes.Add(gBox1);

                        for (i2 = 0; i2 < i; i2++)
                        {
                            gBox2 = new GroupBox();
                            gBox2.Text = sList[i2];

                            if (gbX_S_SESC3 + (mX * i3) > 482) //IF the value of X has reached 429, move down to a new row
                            {
                                i4 += 1;
                                i3 = 0;
                                gBox2.Location = new Point(gbX_S_SESC3, gbY_S_SESC3 + (mY * i4));
                                i3 += 1;
                            }

                            else //Else if the value of X is less than or equal to 482
                            {
                                gBox2.Location = new Point(gbX_S_SESC3 + (mX * i3), gbY_S_SESC3 + (mY * i4));
                                i3 += 1;
                            }

                            gBox2.Size = new System.Drawing.Size(gbW_SESC, gbH_SESC);


                            label1 = new Label();
                            label2 = new Label();
                            tBox1 = new TextBox();
                            tBox2 = new TextBox();

                            label1.Text = "Low ID";
                            label2.Text = "High ID";

                            tBox1.Text = wCIDS.ElementAt(i5);
                            tBox2.Text = wCIDS.ElementAt(i5 + 1);

                            i5 += 2;

                            label1.Location = new Point(lbLX_SESC, lbLY_SESC);
                            label2.Location = new Point(lbHX_SESC, lbHY_SESC);
                            tBox1.Location = new Point(tbLX_SESC, tbLY_SESC);
                            tBox2.Location = new Point(tbHX_SESC, tbHY_SESC);

                            label1.Size = new System.Drawing.Size(lbLW_SESC, lbH_SESC);
                            label2.Size = new System.Drawing.Size(lbHW_SESC, lbH_SESC);

                            tBox1.Size = new System.Drawing.Size(tbW_SESC, tbH_SESC);
                            tBox2.Size = new System.Drawing.Size((tbW_SESC), tbH_SESC);

                            addControl(gBoxes2, gBox2);
                            addControl(labels, label1);
                            addControl(labels, label2);
                            addControl(tBoxes, tBox1);
                            addControl(tBoxes, tBox2);
                        }

                        //Reset each time we go through
                        i3 = 0;
                        i4 = 0;
                    }

                    rControls("singular", "mode2");
                }

                else if (flag2 == "compact")
                {
                    for (i1 = 0; i1 < i; i1++)
                    {
                        label1 = new Label();
                        label1.Text = sList[i1];

                        label1.Location = new Point(lbX_SESC_C, lbY_SESC_C + (mY3 * i1));

                        label1.Size = new System.Drawing.Size(lbW_SESC_C, lbH_SESC_C);

                        tBox1 = new TextBox();
                        tBox1.Text = idList.ElementAt(i1);

                        tBox1.Location = new Point(tbX_SESC_C, tbY_SESC_C + (mY3 * i1));

                        tBox1.Size = new System.Drawing.Size(tbW_SESC_C, tbH_SESC_C);

                        addControl(labels2, label1);
                        addControl(tBoxes2, tBox1);
                    }

                    rControls("compact", "mode1");
                }
            }

            else if (flag == "mids")
            {
                if (flag2 == "singular")
                {
                    for (i1 = 0; i1 < 2; i1++)
                    {
                        if (i1 == 0)
                        {
                            gBox1 = new GroupBox();
                            gBox1.Text = "Non-Specific Mining Laser ID Ranges";

                            gBox1.Location = new Point(gbX_S_SESC4, gbY_S_SESC4);
                            gBox1.Size = new System.Drawing.Size(gbW_SESC3, gbH_SESC3);

                            gBoxes.Add(gBox1);

                            for (i2 = 0; i2 < i; i2++)
                            {
                                gBox2 = new GroupBox();
                                gBox2.Text = sList[i2];

                                if (gbX_S_SESC6 + (mX2 * i3) > 384) //IF the value of X has reached 429, move down to a new row
                                {
                                    i4 += 1;
                                    i3 = 0;
                                    gBox2.Location = new Point(gbX_S_SESC6, gbY_S_SESC6 + (mY4 * i4));
                                    i3 += 1;
                                }

                                else //Else if the value of X is less than or equal to 482
                                {
                                    gBox2.Location = new Point(gbX_S_SESC6 + (mX2 * i3), gbY_S_SESC6 + (mY4 * i4));
                                    i3 += 1;
                                }

                                gBox2.Size = new System.Drawing.Size(gbW_SESC, gbH_SESC);


                                label1 = new Label();
                                label2 = new Label();
                                tBox1 = new TextBox();
                                tBox2 = new TextBox();

                                label1.Text = "Low ID";
                                label2.Text = "High ID";

                                tBox1.Text = idList.ElementAt(i5);
                                tBox2.Text = idList.ElementAt(i5 + 1);

                                i5 += 2;

                                label1.Location = new Point(lbLX_SESC, lbLY_SESC);
                                label2.Location = new Point(lbHX_SESC, lbHY_SESC);
                                tBox1.Location = new Point(tbLX_SESC, tbLY_SESC);
                                tBox2.Location = new Point(tbHX_SESC, tbHY_SESC);

                                label1.Size = new System.Drawing.Size(lbLW_SESC, lbH_SESC);
                                label2.Size = new System.Drawing.Size(lbHW_SESC, lbH_SESC);

                                tBox1.Size = new System.Drawing.Size(tbW_SESC, tbH_SESC);
                                tBox2.Size = new System.Drawing.Size((tbW_SESC), tbH_SESC);

                                addControl(gBoxes2, gBox2);
                                addControl(labels, label1);
                                addControl(labels, label2);
                                addControl(tBoxes, tBox1);
                                addControl(tBoxes, tBox2);
                            }

                            i3 = 0;
                            i4 = 0;
                        }

                        else if (i1 == 1)
                        {
                            gBox1 = new GroupBox();
                            gBox1.Text = "Mining Laser ID Ranges";

                            gBox1.Location = new Point(gbX_S_SESC5, gbY_S_SESC5);
                            gBox1.Size = new System.Drawing.Size(gbW_SESC4, gbH_SESC4);

                            gBoxes.Add(gBox1);

                            mlList = new string[2];
                            mlList[0] = "Mining Lasers";
                            mlList[1] = "Strip Miners";

                            for (i2 = 0; i2 < 2; i2++)
                            {
                                gBox3 = new GroupBox();
                                gBox3.Text = mlList[i2];

                                if (gbX_S_SESC6 + (mX2 * i3) > 383) //IF the value of X has reached 429, move down to a new row
                                {
                                    i4 += 1;
                                    i3 = 0;
                                    gBox3.Location = new Point(gbX_S_SESC6, gbY_S_SESC6 + (mY4 * i4));
                                    i3 += 1;
                                }

                                else //Else if the value of X is less than or equal to 482
                                {
                                    gBox3.Location = new Point(gbX_S_SESC6 + (mX2 * i3), gbY_S_SESC6 + (mY4 * i4));
                                    i3 += 1;
                                }

                                gBox3.Size = new System.Drawing.Size(gbW_SESC, gbH_SESC);

                                label1 = new Label();
                                label2 = new Label();
                                tBox1 = new TextBox();
                                tBox2 = new TextBox();

                                label1.Text = "Low ID";
                                label2.Text = "High ID";

                                tBox1.Text = idList.ElementAt(i5);
                                tBox2.Text = idList.ElementAt(i5 + 1);

                                i5 += 2;

                                label1.Location = new Point(lbLX_SESC, lbLY_SESC);
                                label2.Location = new Point(lbHX_SESC, lbHY_SESC);
                                tBox1.Location = new Point(tbLX_SESC, tbLY_SESC);
                                tBox2.Location = new Point(tbHX_SESC, tbHY_SESC);

                                label1.Size = new System.Drawing.Size(lbLW_SESC, lbH_SESC);
                                label2.Size = new System.Drawing.Size(lbHW_SESC, lbH_SESC);

                                tBox1.Size = new System.Drawing.Size(tbW_SESC, tbH_SESC);
                                tBox2.Size = new System.Drawing.Size((tbW_SESC), tbH_SESC);

                                addControl(gBoxes3, gBox3);
                                addControl(labels2, label1);
                                addControl(labels2, label2);
                                addControl(tBoxes2, tBox1);
                                addControl(tBoxes2, tBox2);
                            }
                        }
                    }

                    rControls("singular", "mode3");
                }
            }
        }


        //Add Controls to lists
        private void addControl(List<Control> cList, Control con)
        {
            cList.Add(con);
        }

        //Register Controls
        private void rControls(string flag1, string flag2)
        {
            if (flag1 == "singular")
            {
                if (flag2 == "mode1")
                {
                    i3 = 0; //Do this here so we are not resetting it either each time we go through the first for loop or the nested for loop.  This will track the elements to use from the collections

                    for (i1 = 0; i1 < gBoxes.Count(); i1++)
                    {
                        gBoxes.ElementAt(i1).Show();

                        //Add the current GroupBox to this
                        this.Controls.Add(gBoxes.ElementAt(i1));


                        //Now add two labels and textboxes
                        for (i2 = 0; i2 < 2; i2++, i3++)
                        {
                            //Show these
                            labels.ElementAt(i3).Show();
                            tBoxes.ElementAt(i3).Show();

                            //Now add them to the groupbox
                            gBoxes.ElementAt(i1).Controls.Add(labels.ElementAt(i3));
                            gBoxes.ElementAt(i1).Controls.Add(tBoxes.ElementAt(i3));

                        }
                    }
                }

                else if (flag2 == "mode2")
                {
                    i3 = 0;
                    i5 = 0;

                    for (i1 = 0; i1 < gBoxes.Count(); i1++)
                    {                        
                        gBoxes.ElementAt(i1).Show();

                        this.Controls.Add(gBoxes.ElementAt(i1));

                        for (i2 = 0; i2 < scTypes; i2++, i3++)
                        {
                            gBoxes2.ElementAt(i3).Show();

                            this.Controls[i1+1].Controls.Add(gBoxes2.ElementAt(i3));

                            for (i4 = 0; i4 < 2; i4++, i5++)
                            {
                                //Show These
                                labels.ElementAt(i5).Show();
                                tBoxes.ElementAt(i5).Show();

                                //Now add them to the groupbox
                                this.Controls[i1+1].Controls[i2].Controls.Add(labels.ElementAt(i5));
                                this.Controls[i1+1].Controls[i2].Controls.Add(tBoxes.ElementAt(i5));
                            }
                        }

                        //i3 = 0;
                    }

                    //MessageBox.Show(null, this.Controls[1].Controls.Count.ToString(), "Test", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }

                else if (flag2 == "mode3")
                {
                    i3 = 0;
                    i5 = 0;

                    for (i1 = 0; i1 < gBoxes.Count(); i1++)
                    {
                        gBoxes.ElementAt(i1).Show();

                        this.Controls.Add(gBoxes.ElementAt(i1));

                        if (i1 == 0)
                        {
                            for (i2 = 0; i2 < gBoxes2.Count(); i2++, i3++)
                            {
                                gBoxes2.ElementAt(i3).Show();

                                this.Controls[i1+1].Controls.Add(gBoxes2.ElementAt(i3));

                                for (i4 = 0; i4 < 2; i4++, i5++)
                                {
                                    labels.ElementAt(i5).Show();
                                    tBoxes.ElementAt(i5).Show();

                                    this.Controls[i1+1].Controls[i2].Controls.Add(labels.ElementAt(i5));
                                    this.Controls[i1+1].Controls[i2].Controls.Add(tBoxes.ElementAt(i5));
                                }
                            }
                        }

                        if (i1 == 1)
                        {
                            i3 = 0;
                            i5 = 0;

                            for (i2 = 0; i2 < gBoxes3.Count(); i2++, i3++)
                            {
                                gBoxes3.ElementAt(i2).Show();

                                this.Controls[i1+1].Controls.Add(gBoxes3.ElementAt(i2));

                                for (i4 = 0; i4 < 2; i4++, i5++)
                                {
                                    labels2.ElementAt(i5).Show();
                                    tBoxes2.ElementAt(i5).Show();

                                    this.Controls[i1+1].Controls[i2].Controls.Add(labels2.ElementAt(i5));
                                    this.Controls[i1+1].Controls[i2].Controls.Add(tBoxes2.ElementAt(i5));
                                }
                            }
                        }
                    }
                }
            }

            else if (flag1 == "compact")
            {
                if (flag2 == "mode1")
                {
                    for (i1 = 0; i1 < labels2.Count(); i1++)
                    {
                        labels2.ElementAt(i1).Show();
                        tBoxes2.ElementAt(i1).Show();

                        //Add the current GroupBox to this
                        this.Controls.Add(labels2.ElementAt(i1));
                        this.Controls.Add(tBoxes2.ElementAt(i1));
                    }
                }

                else if (flag2 == "mode2")
                {

                }
            }

            //Enable Clear Data Button
            m_CData.Enabled = true;

            //Enable Save Menu Option
            m_F_Save.Enabled = true;
        }

        //Delete Controls
        private void m_CData_Click(object sender, EventArgs e)
        {
            if (m_M_Compact.Checked)
            {
                if (m_DT_MLasers.Checked)
                {
                    dControls("compact", "mode2");
                }

                else if (m_DT_Ships.Checked)
                {
                    dControls("compact", "mode1");
                }

                else if (m_DT_SShips.Checked)
                {
                    dControls("compact", "mode1");
                }

                else if (m_DT_Weaps.Checked)
                {
                    dControls("compact", "mode2");
                }

            }

            else if (m_M_Singular.Checked)
            {
                if (m_DT_MLasers.Checked)
                {
                    dControls("singular", "mode2");
                }

                else if (m_DT_Ships.Checked)
                {
                    dControls("singular", "mode1");
                }

                else if (m_DT_SShips.Checked)
                {
                    dControls("singular", "mode1");
                }

                else if (m_DT_Weaps.Checked)
                {
                    dControls("singular", "mode2");
                }
            }
        }

        private void dControls(string flag1, string flag2)
        {
            if (flag1 == "compact")
            {
                //Remove any and all dynamic controls before returning to menu
                for (i1 = 0; i1 < this.Controls.Count; i1++)
                {
                    if (this.Controls[i1] is Label || this.Controls[i1] is TextBox)
                    {
                        this.Controls[i1].Dispose();
                        i1--;
                    }
                }

                //Clear Lists
                if (flag2 == "mode1")
                {
                    sCIDS.Clear();
                }

                else if (flag2 == "mode2")
                {
                    wCIDS.Clear();
                }

                labels2.Clear();
                tBoxes2.Clear();
            }

            else if (flag1 == "singular")
            {
                if (flag2 == "mode1")
                {
                    bCanDelete = false;

                    //Remove any and all dynamic controls before returning to menu
                    for (i1 = 0; i1 < this.Controls.Count; i1++)
                    {
                        if (this.Controls[i1] is GroupBox)
                        {
                            foreach (Control con in this.Controls[i1].Controls)
                            {
                                if (con is Label || con is TextBox)
                                {
                                    con.Dispose();
                                    bCanDelete = true;
                                }
                            }

                            if (bCanDelete)
                            {
                                this.Controls[i1].Dispose();
                                i1--;
                                bCanDelete = false;
                            }
                        }
                    }

                    //Clear All Lists
                    gBoxes.Clear();
                    labels.Clear();
                    tBoxes.Clear();
                    sCIDS.Clear();
                }

                else if (flag2 == "mode2")
                {
                    bCanDelete = false;

                    //Remove any and all dynamic controls before returning to menu
                    for (i1 = 0; i1 < this.Controls.Count; i1++)
                    {
                        if (this.Controls[i1] is GroupBox)
                        {
                            foreach (Control con in this.Controls[i1].Controls)
                            {
                                if (con is GroupBox)
                                {
                                    foreach (Control con2 in con.Controls)
                                    {
                                        if (con2 is Label || con2 is TextBox)
                                        {
                                            con2.Dispose();
                                            bCanDelete = true;
                                        }
                                    }

                                    con.Dispose();
                                }
                            }

                            if (bCanDelete)
                            {
                                this.Controls[i1].Dispose();
                                i1--;
                                bCanDelete = false;
                            }
                        }
                    }

                    if (m_DT_Weaps.Checked)
                    {
                        gBoxes.Clear();
                        gBoxes2.Clear();
                        labels.Clear();
                        tBoxes.Clear();
                        wCIDS.Clear();
                        temp3.Clear();
                    }

                    else if (m_DT_MLasers.Checked)
                    {
                        gBoxes.Clear();
                        gBoxes2.Clear();
                        gBoxes3.Clear();
                        labels.Clear();
                        tBoxes.Clear();
                        labels2.Clear();
                        tBoxes2.Clear();
                        mCIDS.Clear();
                        temp3.Clear();
                    }
                }
            }

            //Disable Clear Data
            m_CData.Enabled = false;

            //Disable Save Menu Option
            m_F_Save.Enabled = false;
        }

        private void m2_File_Click(object sender, EventArgs e)
        {

        }

        private void m_F_Save_Click(object sender, EventArgs e)
        {
            MessageBox.Show(null, "Saving Settings...", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

            if (m_M_Compact.Checked)
            {
                if (m_DT_MLasers.Checked)
                {

                }

                if (m_DT_Ships.Checked)
                {
                    saveINI("singular", "ship_ids");
                }

                else if (m_DT_SShips.Checked)
                {
                    saveINI("compact", "sship_ids");
                }

                else if (m_DT_Weaps.Checked)
                {
                    saveINI("compact", "weap_ids");
                }
            }

            else if (m_M_Singular.Checked)
            {
                if (m_DT_MLasers.Checked)
                {

                }

                if (m_DT_Ships.Checked)
                {
                    saveINI("singular", "ship_ids");
                }

                else if (m_DT_SShips.Checked)
                {
                    saveINI("singular", "sship_ids");
                }

                else if (m_DT_Weaps.Checked)
                {
                    saveINI("singular", "weap_ids");
                }
            }
        }

        private void saveINI(string flag1, string flag2)
        {
            data = "";
            i1 = 0;
            i2 = 0;

            if (flag1 == "singular")
            {
                if (flag2 == "ship_ids")
                {
                    //Reform the ID string from group box elements
                    foreach (GroupBox gb in gBoxes)
                    {
                        foreach (Control con in gb.Controls)
                        {
                            if (con is TextBox)
                            {
                                if (i1 == 1)
                                {
                                    data = data + "-" + con.Text;
                                }

                                else
                                {
                                    data = data + con.Text;
                                    i1 += 1;
                                }
                            }
                        }

                        if (i2 < 8)
                        {
                            data = data + ",";
                            i1 = 0;
                        }

                        i2 += 1;
                    }

                    //MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    iF_S.Write("sidrstr", data, "itemid");
                }

                else if (flag2 == "sship_ids")
                {
                    //Reform the ID string from group box elements
                    foreach (GroupBox gb in gBoxes)
                    {
                        foreach (Control con in gb.Controls)
                        {
                            if (con is TextBox)
                            {
                                if (i1 == 1)
                                {
                                    data = data + "-" + con.Text;
                                }

                                else
                                {
                                    data = data + con.Text;
                                    i1 += 1;
                                }
                            }
                        }
                    }

                    //MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    iF_S.Write("ssrstr", data, "itemid");
                }
            }

            else if (flag1 == "compact")
            {
                if (flag2 == "ship_ids")
                {
                    iF_S.Write("sidrstr", tb_SESC_C.Text, "itemid");
                }

                else if (flag2 == "sship_ids")
                {
                    iF_S.Write("ssrstr", tb_SESC_C.Text, "itemid");
                }
            }
        }

        /*
         *  private void cbox_VSelect_SIC(object sender, EventArgs e)
        {
            //Disable rabio buttons
            rb_Compact.Enabled = false;
            rb_Single.Enabled = false;

                    

            else if (cbox_VSelect.SelectedIndex == 1)
            {
               
            }

            else if (cbox_VSelect.SelectedIndex == 2)
            {
                
            }

            else if (cbox_VSelect.SelectedIndex == 3)
            {
               
                }
            }
        }

        private void addControls(int i, string[] sList, List<string> idList, string flag, string flag2)
        {
           
        }

        private void sControls(string flag, string flag2)
        {
           
        }*/
         
          private void btn_SE_Save_Click(object sender, EventArgs e)
        {
            MessageBox.Show(null, "Saving Settings...", "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

            if (m_DT_MLasers.Checked)
            {
                if (m_M_Singular.Checked)
                {
                    saveSettings("singular", "mlaser_ids");
                }

                else if (m_M_Compact.Checked)
                {
                    saveSettings("compact", "mlaser_ids");
                }
            }

            else if (m_DT_Ships.Checked)
            {
                if (m_M_Singular.Checked)
                {
                    saveSettings("singular", "ship_ids");
                }

                else if (m_M_Compact.Checked)
                {
                    saveSettings("compact", "ship_ids");
                }
            }

            else if (m_DT_SShips.Checked)
            {
                if (m_M_Singular.Checked)
                {
                    saveSettings("singular", "sship_ids");
                }

                else if (m_M_Compact.Checked)
                {
                    saveSettings("compact", "sship_ids");
                }
            }

            else if (m_DT_Weaps.Checked)
            {
                if (m_M_Singular.Checked)
                {
                    saveSettings("singular","weap_ids");
                }

                else if (m_M_Compact.Checked)
                {
                    saveSettings("compact","weap_ids");
                }
            }
        }

        private void saveSettings(string flag1, string flag2)
        {
            iF_S = new iniFile(gVars.ovs_local);

            data = "";
            i1 = 0;
            i2 = 0;

            if (flag1 == "singular")
            {
                if (flag2 == "mlaser_ids")
                {
                    foreach (GroupBox gb1 in gBoxes)
                    {
                        foreach (GroupBox gb2 in gb1.Controls)
                        {
                            foreach (Control con in gb2.Controls)
                            {
                                if (con is TextBox)
                                {
                                    if (i1 == 1)
                                    {
                                        data = data + "-" + con.Text;
                                    }

                                    else
                                    {
                                        data = data + con.Text;
                                        i1++;
                                    }
                                }
                            }

                            if (i2 < gb2.Controls.Count)
                            {
                                data = data + ",";
                                i1 = 0;
                                i2++;
                            }

                            if (i2 == gb2.Controls.Count)
                            {
                                data = data + ";";
                                i2 = 0;
                            }
                        }
                    }

                    MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    //iF_S.Write("mlidrstr", data, "itemid");
                }
                    
                else if (flag2 == "ship_ids")
                {
                    //Reform the ID string from group box elements
                    foreach (GroupBox gb in gBoxes)
                    {
                        foreach (Control con in gb.Controls)
                        {
                            if (con is TextBox)
                            {
                                if (i1 == 1)
                                {
                                    data = data + "-" + con.Text;
                                }

                                else
                                {
                                    data = data + con.Text;
                                    i1++;
                                }
                            }
                        }

                        if (i2 < gb.Controls.Count)
                        {
                            data = data + ",";
                            i1 = 0;
                            i2++;
                        }
                    }

                    //MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    
                    iF_S.Write("sidrstr", data, "itemid");
                }

                else if (flag2 == "sship_ids")
                {
                    //Reform the ID string from group box elements
                    foreach (GroupBox gb in gBoxes)
                    {
                        foreach (Control con in gb.Controls)
                        {
                            if (con is TextBox)
                            {
                                if (i1 == 1)
                                {
                                    data = data + "-" + con.Text;
                                }

                                else
                                {
                                    data = data + con.Text;
                                    i1 += 1;
                                }
                            }
                        }
                    }

                    //MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    iF_S.Write("ssrstr", data, "itemid");
                }

                else if (flag2 == "weap_ids")
                {
                    foreach (GroupBox gb1 in gBoxes)
                    {
                        foreach (GroupBox gb2 in gb1.Controls)
                        {
                            foreach (Control con in gb2.Controls)
                            {
                                if (con is TextBox)
                                {
                                    if (i1 == 1)
                                    {
                                        data = data + "-" + con.Text;
                                    }

                                    else
                                    {
                                        data = data + con.Text;
                                        i1++;
                                    }
                                }
                            }

                            if (i2 < gb2.Controls.Count)
                            {
                                data = data + ",";
                                i1 = 0;
                                i2++;
                            }

                            if (i2 == gb2.Controls.Count)
                            {
                                data = data + ";";
                                i2 = 0;
                            }
                        }
                    }

                    MessageBox.Show(null, data, "Information", MessageBoxButtons.OK, MessageBoxIcon.Information);

                    //iF_S.Write("widrstr", data, "itemid");
                }
            }

            else if (flag1 == "compact")
            {
                if (flag2 == "mlaser_ids")
                {
                    iF_S.Write("mlidrstr", tb_SESC_C.Text, "itemid");
                }
                
                else if (flag2 == "ship_ids")
                {
                    iF_S.Write("sidrstr", tb_SESC_C.Text, "itemid");
                }

                else if (flag2 == "sship_ids")
                {
                    iF_S.Write("ssrstr", tb_SESC_C.Text, "itemid");
                }

                if (flag2 == "weap_ids")
                {
                    iF_S.Write("widrstr", tb_SESC_C.Text, "itemid");
                }
            }
        }
         /* 
         private void mainReturn(string flag1, string flag2, string flag3)
       {
           if (flag1 == "se")
           {
               //Window Changes
               rb_Single.Visible = false;
               rb_Compact.Visible = false;
               btn_SE_Cancel.Visible = false;
               btn_SE_Save.Visible = false;
               cbox_VSelect.SelectedIndex = -1;
               cbox_VSelect.Text = "Select a Value to Import";
               cbox_VSelect.Visible = false;
               p_SEditor.Visible = false;
               mMSG.Visible = true;
               seBtn.Visible = true;
               dbeBtn.Visible = true;

               //Menu Changes
               mSS.Visible = false;
               mSep5.Visible = false;
               mSE.Visible = true;
               mRWP.Visible = false;

               //Enable rabio buttons
               rb_Compact.Enabled = true;
               rb_Single.Enabled = true;

               if (flag2 == "compact")
               {
                   //Remove any and all dynamic controls before returning to menu
                   for (i1 = p_SEditor.Controls.Count - 1; i1 > -1; i1--)
                   {
                       if (p_SEditor.Controls[i1] is Label || p_SEditor.Controls[i1] is TextBox)
                       {
                           p_SEditor.Controls[i1].Dispose();
                       }                      
                   }

                    //Clear Lists
                   if (flag3 == "mode1")
                   {
                       sCIDS.Clear();
                   }

                   else if (flag3 == "mode2")
                   {
                       wCIDS.Clear();
                   }
                  
                   labels2.Clear();
                   tBoxes2.Clear();
               }

               else if (flag2 == "singular")
               {
                   if (flag3 == "mode1")
                   {
                       bCanDelete = false;

                       //Remove any and all dynamic controls before returning to menu
                       for (i1 = p_SEditor.Controls.Count - 1; i1 > -1; i1--)
                       {
                           if (p_SEditor.Controls[i1] is GroupBox)
                           {
                               foreach (Control con in p_SEditor.Controls[i1].Controls)
                               {
                                   if (con is Label || con is TextBox)
                                   {
                                       con.Dispose();
                                       bCanDelete = true;
                                   }
                               }

                               if (bCanDelete)
                               {
                                   p_SEditor.Controls[i1].Dispose();
                                   bCanDelete = false;
                               }
                           }
                       }

                       //Clear All Lists
                       gBoxes.Clear();
                       labels.Clear();
                       tBoxes.Clear();
                       sCIDS.Clear();
                   }

                   else if (flag3 == "mode2")
                   {
                       bCanDelete = false;

                       //Remove any and all dynamic controls before returning to menu
                       for (i1 = p_SEditor.Controls.Count - 1; i1 > -1; i1--)
                       {
                           if (p_SEditor.Controls[i1] is GroupBox)
                           {
                               foreach (Control con in p_SEditor.Controls[i1].Controls)
                               {
                                   if (con is GroupBox)
                                   {
                                       foreach (Control con2 in con.Controls)
                                       {
                                           if (con2 is Label || con2 is TextBox)
                                           {
                                               con2.Dispose();
                                               bCanDelete = true;
                                           }
                                       }

                                       con.Dispose();
                                   }
                               }

                               if (bCanDelete)
                               {
                                   p_SEditor.Controls[i1].Dispose();
                                   bCanDelete = false;
                               }
                           }
                       }

                       //Clear All Lists
                       gBoxes.Clear();
                       gBoxes2.Clear();
                       labels.Clear();
                       tBoxes.Clear();
                       wCIDS.Clear();
                       temp3.Clear();
                   }                   
               }
           }
       }*/
         
        private bool isNMBarge(string s)
        {
            return s != "Mining_Barge";
        }

        private string upperFChar(string s)
        {
            // Return char and concat substring.
            return char.ToUpper(s[0]) + s.Substring(1);
        }

        private void m_DT_PData_Click(object sender, EventArgs e)
        {
            sCheck(3, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_PData.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_PData.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_Empires_Click(object sender, EventArgs e)
        {
            sCheck(0, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_Empires.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_Empires.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_Items_Click(object sender, EventArgs e)
        {
            sCheck(1, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_Items.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_Items.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

        private void m_DT_Races_Click(object sender, EventArgs e)
        {
            sCheck(4, m_DType.DropDownItems);

            if ((bDTSelected) && (!m_DT_Races.Checked))
            {
                bDTSelected = false;
            }

            else if ((!bDTSelected) && (m_DT_Races.Checked))
            {
                bDTSelected = true;
            }

            bCheck();
        }

    }

    class myRenderer : ToolStripProfessionalRenderer
    {
        protected override void OnRenderMenuItemBackground(ToolStripItemRenderEventArgs myMenu)
        {
            if (!myMenu.Item.Selected)
                base.OnRenderMenuItemBackground(myMenu);
            else
            {
                Rectangle menuRectangle = new Rectangle(Point.Empty, myMenu.Item.Size);
                //Fill Color
                myMenu.Graphics.FillRectangle(Brushes.LightSkyBlue, menuRectangle);
                // Border Color
                myMenu.Graphics.DrawRectangle(Pens.AntiqueWhite, 1, 0, menuRectangle.Width - 2, menuRectangle.Height - 1);
            }
        }
    }
}

